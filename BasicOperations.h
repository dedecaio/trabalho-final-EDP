void insereConteudo(ARVORE** arvore, int codigo, char conteudo[], int ePergunta){
	if(*arvore == NULL){
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE ));
		if(no){
			no->info.codigo = codigo;
			no->info.ePergunta = ePergunta;
			strcpy(no->info.conteudo, conteudo);
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
//			printf("\nRegistro inserido");
		}
	}else{
		if((*arvore)->info.codigo > codigo)
			insereConteudo(&(*arvore)->sube, codigo,conteudo,ePergunta);
		else if((*arvore)->info.codigo < codigo)
			insereConteudo(&(*arvore)->subd, codigo, conteudo,ePergunta);
		else{
			// o registro já foi inserido	
		}
		
	}
}

void imprime(ARVORE* arv){
	if(arv) {              // verifica se a raiz é diferente de vazio
		printf( "\n >> sube " );       //"de %i", aux->info.codigo );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n Código.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.conteudo );
		getchar();
		printf( "\n >> subd " );       //"de %i", aux->info.codigo );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Subárvore vazia!\n");
}

int buscar(ARVORE* arvore, int codigo)  {
	if (arvore == NULL) {
		return -1;
	}
	
	if (codigo == arvore->info.codigo && arvore->info.ePergunta == 0) {
		return 1;
	} else if (codigo < arvore->info.codigo) {
		return buscar(arvore->sube, codigo);
	} else {
		return buscar(arvore ->subd, codigo);
	}
}

void removeArvore(ARVORE** arvore, int codigo){
	
	if (*arvore) {
		if (codigo < (*arvore)->info.codigo) {
			removeArvore(&(*arvore)->sube, codigo);	
		} else if (codigo > (*arvore)->info.codigo) {
			removeArvore(&(*arvore)->subd, codigo);
		} else {
			ARVORE *aux = *arvore;
			*arvore = NULL;
			free(aux);
			printf("\nRegistro excluido com sucesso!");
		}
	}else{
		printf("Registro não encontrado");
	}
}

void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE));
	
	if(novo){										// verifica se conseguiu alocar memória para o novo registro
        novo->codigo = codigo;					                           
        strcpy(novo->nome, nome);
        strcpy(novo->descricao, descricao);
        novo->prox = NULL;
        if( *cidades == NULL ){                              // verifica se a lista está vazia, caso sim terá que ajustar o início da lista
            novo->id = 1;
			*cidades = novo;                                // insere o primeiro registro
            
        }else{
            CIDADE *aux;                                // define ponteiro auxiliar             
            aux = *cidades;                             // posiciona ponteiro auxiliar na lista
            while( aux->prox != NULL )                // percorre a lista até encontrar o último registro
                aux = aux->prox;
            novo->id = aux->id;
            novo->id++;
            aux->prox = novo;                         // último registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

void imprimeCidades(CIDADE* cidades){
	if(cidades){
		while(cidades != NULL){
			printf("\nId: %d | Nome: %s",cidades->id,cidades->nome);
			printf("\nDescrição: %s",cidades->descricao);
			cidades = cidades->prox;
		}
		
	}else
		printf("Lista vazia");
}
CIDADE* buscaCidades(CIDADE* cidades, int codigo){
	CIDADE* lista = NULL;
	while (cidades != NULL){
		if (cidades->codigo == codigo){
			insereCidade(&lista, cidades->codigo, cidades->nome, cidades->descricao);
		}
		cidades = cidades->prox;
	}
	return lista;
}

CIDADE* procuraRegistro(CIDADE* aux, int id){
	while( aux != NULL ){
	       if( aux->id == id ) 
		       return aux;
	       aux = aux->prox; 
    }
    return NULL;
}

void removeCidade(CIDADE** cidades){
	int id;
	    
    if( *cidades ){
	    printf( "\nQual o id da cidade que deseja excluir? ");
	    scanf( "%d", &id );
	    CIDADE* aux = procuraRegistro(*cidades,id);
	    if(aux){
	    	CIDADE* ptLista = *cidades;
	    	if(ptLista == aux){
	    		*cidades = ptLista->prox;
			}else{
				while(ptLista->prox != aux)
		    		ptLista = ptLista->prox;
				ptLista->prox = aux->prox;
			}
			free(aux);
			printf("Registro excluído");
	    	
		}else
			printf("Registro não encontrado");
	    
    }else     
        printf( "\nLista de cidades vazia!" );
}

void insereFeedbackLista(FEEDBACK** feedback, char nome[], char email[], char comentario[]){
	FEEDBACK* novo = (FEEDBACK *) malloc(sizeof(FEEDBACK));
	
	if(novo){
		strcpy(novo->nome,nome);
		strcpy(novo->email,email);
		strcpy(novo->comentario,comentario);
		novo->prox = NULL;
		if(*feedback == NULL){
			novo->id = 1;
			*feedback = novo;
		}else{
			FEEDBACK *aux = *feedback;
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			novo->id = aux->id;
			novo->id++;
			aux->prox = novo;
		}
	}else
		printf("Lista cheia!");
}

void imprimeFeedback(FEEDBACK* feedback){
	if(feedback){
		while(feedback){
			printf("\nId: %d | Nome: %s",feedback->id,feedback->nome);
			printf("\nComentário: %s",feedback->comentario);
			printf("\nContato: %s\n",feedback->email);
			feedback = feedback->prox;
		}
		
	}else
		printf("Lista vazia");
}
