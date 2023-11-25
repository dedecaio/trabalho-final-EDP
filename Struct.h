typedef struct cidade{
	char nome[50], descricao[400]; // nome e descrição de cada cidade
	int codigo;					  // codigo que será o mesmo da folha da árvore
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de referência para ajudar na inserção correta na árvore
	char conteudo[200]; // pergunta ou resposta
	int ePergunta; // Se for 1 é se for 0 não é
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;



