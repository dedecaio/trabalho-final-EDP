typedef struct cidade{
	char nome[100], descricao[800]; // nome e descri��o de cada cidade
	int id,codigo;					  // codigo que ser� o mesmo da folha da �rvore
	struct cidade* prox;
} CIDADE;

typedef struct info{
	int codigo; // codigo de refer�ncia para ajudar na inser��o correta na �rvore
	char conteudo[400]; // pergunta ou resposta
	int ePergunta; // Se for 1 � se for 0 n�o �
}INFO;

typedef struct arvore{
	INFO info;
	struct arvore *subd;
	struct arvore *sube;
}ARVORE;

typedef struct feedback{
	int id;
	char nome[30], email[50], comentario[400];
	struct feedback* prox;	
}FEEDBACK;
