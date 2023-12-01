typedef struct cidade{
	char nome[50], descricao[600]; // nome e descrição de cada cidade
	int id,codigo;					  // codigo que será o mesmo da folha da árvore
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de referência para ajudar na inserção correta na árvore
	char conteudo[400]; // pergunta ou resposta
	int ePergunta; // Se for 1 é se for 0 não é
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;



