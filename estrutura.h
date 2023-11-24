typedef struct cidade{
	char nome[50], descricao[400];
	int codigo;
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de referência para ajudar na inserção correta na árvore
	char conteudo[200]; // perguntas
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;

void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){
	
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE));
	
	if( novo != NULL ){                                   // verifica se conseguiu alocar memória para o novo registro
        novo->codigo = codigo					                           
        strcpy(novo->nome, nome);
        strcpy(novo->descricao, descricao);
        if( *cidade == NULL )                              // verifica se a lista está vazia, caso sim terá que ajustar o início da lista
            *cidade = novo;                                // insere o primeiro registro
        else{
             CIDADE *aux;                                // define ponteiro auxiliar             
             aux = *cidade;                             // posiciona ponteiro auxiliar na lista
             while( aux->prox != NULL )                // percorre a lista até encontrar o último registro
                    aux = aux->prox;
             aux->prox = novo;                         // último registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

