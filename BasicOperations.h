void insereConteudo(ARVORE** arvore, int codigo, char conteudo[], int ePergunta){  // fun��o para inserir conteudo na �rvore
	if(*arvore == NULL){ // v� se a �rvore est� vazia, se sim � o primeiro elemento
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE )); // aloca espa�o
		if(no){ // se foi poss�vel ent�o define os dados do registro da �rvore
			no->info.codigo = codigo; 
			no->info.ePergunta = ePergunta;
			strcpy(no->info.conteudo, conteudo);
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
		}
	}else{ 
		if((*arvore)->info.codigo > codigo)  // se codigo for menor que o do registro atual, percorre pela esquerda
			insereConteudo(&(*arvore)->sube, codigo,conteudo,ePergunta);
		else if((*arvore)->info.codigo < codigo) // se for maior, percorre pela direita
			insereConteudo(&(*arvore)->subd, codigo, conteudo,ePergunta);
		else{
			printf("Registro j� inserido!");
			return;
			// o registro j� foi inserido	
		}
		
	}
}

void imprime(ARVORE* arv){ // fun��o para imprimir arvore 
	if(arv) {              // verifica se o registro atual � diferente de vazio
		printf( "\n >> sube " );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n C�digo.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.conteudo );
		getchar();
		printf( "\n >> subd " );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Sub�rvore vazia!\n");
}

int buscar(ARVORE* arvore, int codigo)  { // fun��o para buscar na �rvore com base no c�digo
	if (arvore == NULL) { // se registro atual for nulo(n�o existir) ent�o retorna -1
		return -1;
	}
	
	if (codigo == arvore->info.codigo && arvore->info.ePergunta == 0) { // achou
		return 1;
	} else if (codigo < arvore->info.codigo) { // menor = esquerda
		return buscar(arvore->sube, codigo);
	} else { // maior = direita
		return buscar(arvore ->subd, codigo); 
	}
}

void removeArvore(ARVORE** arvore, int codigo) { // fun��o que remove o registro e todas as sub�rvores poss�veis
    if (*arvore) { // se registro atual � diferente de NULL
        if (codigo < (*arvore)->info.codigo) { // menor = esquerda
            removeArvore(&(*arvore)->sube, codigo);	
        } else if (codigo > (*arvore)->info.codigo) { // maior = direita
            removeArvore(&(*arvore)->subd, codigo); 
        } else { // achou
            ARVORE *aux = *arvore; // auxiliar
            if ((*arvore)->sube) { // percorre a sub-�rvore � esquerda se existir
                removeArvore(&(*arvore)->sube, (*arvore)->sube->info.codigo);
            }
            if ((*arvore)->subd) { // percorre a sub-�rvore � direita se existir
                removeArvore(&(*arvore)->subd, (*arvore)->subd->info.codigo);
            }
            *arvore = NULL; // define como NULL
            free(aux); // libera espa�o na memoria
            printf("\nRegistro excluido com sucesso!");
        }
    } else {
        printf("Registro n�o encontrado");
    }
}


void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){ // fun��o para inserir em uma lista de cidades
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE)); // aloca espaco para o novo registro
	
	if(novo){ // verifica se conseguiu alocar mem�ria para o novo registro
        novo->codigo = codigo; // define os dados
        strcpy(novo->nome, nome); 
        strcpy(novo->descricao, descricao);
        novo->prox = NULL; // define pr�ximo ponteiro como NULL
        if( *cidades == NULL ){ // verifica se a lista est� vazia, caso sim ter� que ajustar o in�cio da lista
            novo->id = 1; // o primeiro elemento
			*cidades = novo; // insere o primeiro registro
        }else{
            CIDADE *aux = *cidades;  // posiciona ponteiro auxiliar na lista
            while( aux->prox != NULL ) // percorre a lista at� encontrar o �ltimo registro
                aux = aux->prox;
            novo->id = aux->id; // o id do novo elemento ser� igual o �ltimo
            novo->id++; // incrementa para que fique 1 a mais que o �ltimo
            aux->prox = novo; // �ltimo registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

void imprimeCidades(CIDADE* cidades){ // Fun��o para imprimir a lista de cidades
	if(cidades){ // checa se existe
		while(cidades != NULL){ // percorre toda a lista
			printf("\nId: %d | Nome: %s",cidades->id,cidades->nome);
			printf("\nDescri��o: %s",cidades->descricao);
			cidades = cidades->prox;
		}
	}else
		printf("Lista vazia");
}
CIDADE* buscaCidades(CIDADE* cidades, int codigo){ // fun��o que busca por cidades que possuam x c�digo. Retornando uma lista de cidades s� com o x c�digo
	CIDADE* lista = NULL; // lista que ir� ser retornada
	while (cidades != NULL){ // percorre toda a lista
		if (cidades->codigo == codigo){ // se for igual ao codigo insere na lista que ir� retornar
			insereCidade(&lista, cidades->codigo, cidades->nome, cidades->descricao);
		}
		cidades = cidades->prox;
	}
	return lista;
}

CIDADE* procuraRegistro(CIDADE* aux, int id){ // procura uma cidade com base no id
	while( aux != NULL ){ // percorre
	       if( aux->id == id ) // verifica
		       return aux; // se existir retorna o elemento
	       aux = aux->prox; 
    }
    return NULL; // se n�o existir retorna NULL
}

void removeCidade(CIDADE** cidades){
	int id; // id
	    
    if( *cidades ){ // verifica se lista � diferente de vazio
	    printf( "\nQual o id da cidade que deseja excluir? ");
	    scanf( "%d", &id ); // l� o id
	    CIDADE* aux = procuraRegistro(*cidades,id); // procura o elemento
	    if(aux){ // se ele existe
	    	CIDADE* ptLista = *cidades; // auxiliar
	    	if(ptLista == aux){  // se for o primeiro elemento faz a lista apontar para o pr�ximo
	    		*cidades = ptLista->prox;
			}else{
				while(ptLista->prox != aux) // percorre at� achar o anterior do que deseja se excluir
		    		ptLista = ptLista->prox; 
				ptLista->prox = aux->prox; // agora aponta para o pr�ximo do que se deseja excluir
			}
			free(aux); // libera espa�o
			printf("Registro exclu�do");
	    	
		}else
			printf("Registro n�o encontrado");
	    
    }else     
        printf( "\nLista de cidades vazia!" );
}

void insereFeedbackLista(FEEDBACK** feedback, char nome[], char email[], char comentario[]){ // fun��o de inserir feedback
	FEEDBACK* novo = (FEEDBACK *) malloc(sizeof(FEEDBACK)); // aloca espa�o na mem�ria
	
	if(novo){ // se conseguiu define os dados
		strcpy(novo->nome,nome);
		strcpy(novo->email,email);
		strcpy(novo->comentario,comentario);
		novo->prox = NULL; // pr�ximo sera NULL
		if(*feedback == NULL){ // se for o primeiro
			novo->id = 1; // define id como 1
			*feedback = novo; // aponta para ele
		}else{
			FEEDBACK *aux = *feedback; // ponteiro auxiliar
			while(aux->prox != NULL){ // percorre at� achar o �ltimo
				aux = aux->prox;
			}
			novo->id = aux->id; // iguala os ids
			novo->id++; // incrementa em 1 o do novo elemento
			aux->prox = novo; // insere no fim da lista
		}
	}else
		printf("Lista cheia!");
}

void imprimeFeedback(FEEDBACK* feedback){ // imprime o feedback
	if(feedback){ // verifica se lista est� vazia
		while(feedback){ // percorre ela toda
			printf("\nId: %d | Nome: %s",feedback->id,feedback->nome);
			printf("\nComent�rio: %s",feedback->comentario);
			printf("\nContato: %s\n",feedback->email);
			feedback = feedback->prox;
		}
	}else
		printf("Lista vazia");
}
