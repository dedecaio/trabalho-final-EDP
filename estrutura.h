typedef struct cidade{
	char nome[50], descricao[400];
	int codigo;
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de refer�ncia para ajudar na inser��o correta na �rvore
	char conteudo[200]; // perguntas
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;

void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){
	
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE));
	
	if( novo != NULL ){                                   // verifica se conseguiu alocar mem�ria para o novo registro
        novo->codigo = codigo					                           
        strcpy(novo->nome, nome);
        strcpy(novo->descricao, descricao);
        if( *cidade == NULL )                              // verifica se a lista est� vazia, caso sim ter� que ajustar o in�cio da lista
            *cidade = novo;                                // insere o primeiro registro
        else{
             CIDADE *aux;                                // define ponteiro auxiliar             
             aux = *cidade;                             // posiciona ponteiro auxiliar na lista
             while( aux->prox != NULL )                // percorre a lista at� encontrar o �ltimo registro
                    aux = aux->prox;
             aux->prox = novo;                         // �ltimo registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

