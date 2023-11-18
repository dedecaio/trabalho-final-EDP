typedef struct cidade{
	char nome[50], descricao[200];
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de referência para ajudar na inserção correta na árvore
	CIDADE** cidades; // possivel lista de cidades
	char pergunta[100]; // perguntas
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;
