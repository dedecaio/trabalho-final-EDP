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
