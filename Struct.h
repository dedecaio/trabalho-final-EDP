typedef struct cidade{
	char nome[100], descricao[800]; // nome e descrição de cada cidade
	int id,codigo;					  // codigo que será o mesmo da folha da árvore e o id para que cada registro seja único
	struct cidade* prox;				 // Ponteiro para a próxima cidade
} CIDADE;

typedef struct info{
	int codigo; // codigo de referência para ajudar na inserção correta na árvore
	char conteudo[400]; // pergunta ou resposta
	int ePergunta; // Se for 1 é se for 0 não é
}INFO;

typedef struct arvore{
	INFO info;  // informação que cada registro da árvore terá
	struct arvore *subd;   // Ponteiro para a sub-árvore a direita 
	struct arvore *sube;   // Ponteiro para a sub-árvore a esquerda
}ARVORE;

typedef struct feedback{
	int id; // id para os comentários
	char nome[30], email[50], comentario[400]; // os dados de cada feedback
	struct feedback* prox;	// ponteiro para o próximo comentário
}FEEDBACK;
