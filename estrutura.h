typedef struct cidade{
	char nome[50], descricao[200];
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de refer�ncia para ajudar na inser��o correta na �rvore
	CIDADE** cidades; // possivel lista de cidades
	char pergunta[100]; // perguntas
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;
