void insereConteudo(ARVORE** arvore, int codigo, char conteudo[], int ePergunta){  // função para inserir conteudo na árvore
	if(*arvore == NULL){ // vê se a árvore está vazia, se sim é o primeiro elemento
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE )); // aloca espaço
		if(no){ // se foi possível então define os dados do registro da árvore
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
			printf("Registro já inserido!");
			return;
			// o registro já foi inserido	
		}
		
	}
}

void imprime(ARVORE* arv){ // função para imprimir arvore 
	if(arv) {              // verifica se o registro atual é diferente de vazio
		printf( "\n >> sube " );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n Código.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.conteudo );
		getchar();
		printf( "\n >> subd " );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Subárvore vazia!\n");
}

int buscar(ARVORE* arvore, int codigo)  { // função para buscar na árvore com base no código
	if (arvore == NULL) { // se registro atual for nulo(não existir) então retorna -1
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

void removeArvore(ARVORE** arvore, int codigo) { // função que remove o registro e todas as subárvores possíveis
    if (*arvore) { // se registro atual é diferente de NULL
        if (codigo < (*arvore)->info.codigo) { // menor = esquerda
            removeArvore(&(*arvore)->sube, codigo);	
        } else if (codigo > (*arvore)->info.codigo) { // maior = direita
            removeArvore(&(*arvore)->subd, codigo); 
        } else { // achou
            ARVORE *aux = *arvore; // auxiliar
            if ((*arvore)->sube) { // percorre a sub-árvore à esquerda se existir
                removeArvore(&(*arvore)->sube, (*arvore)->sube->info.codigo);
            }
            if ((*arvore)->subd) { // percorre a sub-árvore à direita se existir
                removeArvore(&(*arvore)->subd, (*arvore)->subd->info.codigo);
            }
            *arvore = NULL; // define como NULL
            free(aux); // libera espaço na memoria
            printf("\nRegistro excluido com sucesso!");
        }
    } else {
        printf("Registro não encontrado");
    }
}


void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){ // função para inserir em uma lista de cidades
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE)); // aloca espaco para o novo registro
	
	if(novo){ // verifica se conseguiu alocar memória para o novo registro
        novo->codigo = codigo; // define os dados
        strcpy(novo->nome, nome); 
        strcpy(novo->descricao, descricao);
        novo->prox = NULL; // define próximo ponteiro como NULL
        if( *cidades == NULL ){ // verifica se a lista está vazia, caso sim terá que ajustar o início da lista
            novo->id = 1; // o primeiro elemento
			*cidades = novo; // insere o primeiro registro
        }else{
            CIDADE *aux = *cidades;  // posiciona ponteiro auxiliar na lista
            while( aux->prox != NULL ) // percorre a lista até encontrar o último registro
                aux = aux->prox;
            novo->id = aux->id; // o id do novo elemento será igual o último
            novo->id++; // incrementa para que fique 1 a mais que o último
            aux->prox = novo; // último registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

void imprimeCidades(CIDADE* cidades){ // Função para imprimir a lista de cidades
	if(cidades){ // checa se existe
		while(cidades != NULL){ // percorre toda a lista
			printf("\nId: %d | Nome: %s",cidades->id,cidades->nome);
			printf("\nDescrição: %s",cidades->descricao);
			cidades = cidades->prox;
		}
	}else
		printf("Lista vazia");
}
CIDADE* buscaCidades(CIDADE* cidades, int codigo){ // função que busca por cidades que possuam x código. Retornando uma lista de cidades só com o x código
	CIDADE* lista = NULL; // lista que irá ser retornada
	while (cidades != NULL){ // percorre toda a lista
		if (cidades->codigo == codigo){ // se for igual ao codigo insere na lista que irá retornar
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
    return NULL; // se não existir retorna NULL
}

void removeCidade(CIDADE** cidades){
	int id; // id
	    
    if( *cidades ){ // verifica se lista é diferente de vazio
	    printf( "\nQual o id da cidade que deseja excluir? ");
	    scanf( "%d", &id ); // lê o id
	    CIDADE* aux = procuraRegistro(*cidades,id); // procura o elemento
	    if(aux){ // se ele existe
	    	CIDADE* ptLista = *cidades; // auxiliar
	    	if(ptLista == aux){  // se for o primeiro elemento faz a lista apontar para o próximo
	    		*cidades = ptLista->prox;
			}else{
				while(ptLista->prox != aux) // percorre até achar o anterior do que deseja se excluir
		    		ptLista = ptLista->prox; 
				ptLista->prox = aux->prox; // agora aponta para o próximo do que se deseja excluir
			}
			free(aux); // libera espaço
			printf("Registro excluído");
	    	
		}else
			printf("Registro não encontrado");
	    
    }else     
        printf( "\nLista de cidades vazia!" );
}

void insereFeedbackLista(FEEDBACK** feedback, char nome[], char email[], char comentario[]){ // função de inserir feedback
	FEEDBACK* novo = (FEEDBACK *) malloc(sizeof(FEEDBACK)); // aloca espaço na memória
	
	if(novo){ // se conseguiu define os dados
		strcpy(novo->nome,nome);
		strcpy(novo->email,email);
		strcpy(novo->comentario,comentario);
		novo->prox = NULL; // próximo sera NULL
		if(*feedback == NULL){ // se for o primeiro
			novo->id = 1; // define id como 1
			*feedback = novo; // aponta para ele
		}else{
			FEEDBACK *aux = *feedback; // ponteiro auxiliar
			while(aux->prox != NULL){ // percorre até achar o último
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
	if(feedback){ // verifica se lista está vazia
		while(feedback){ // percorre ela toda
			printf("\nId: %d | Nome: %s",feedback->id,feedback->nome);
			printf("\nComentário: %s",feedback->comentario);
			printf("\nContato: %s\n",feedback->email);
			feedback = feedback->prox;
		}
	}else
		printf("Lista vazia");
}
