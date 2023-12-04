typedef struct cidade{
	char nome[100], descricao[800]; // nome e descri��o de cada cidade
	int id,codigo;					  // codigo que ser� o mesmo da folha da �rvore e o id para que cada registro seja �nico
	struct cidade* prox;				 // Ponteiro para a pr�xima cidade
} CIDADE;

typedef struct info{
	int codigo; // codigo de refer�ncia para ajudar na inser��o correta na �rvore
	char conteudo[400]; // pergunta ou resposta
	int ePergunta; // Se for 1 � se for 0 n�o �
}INFO;

typedef struct arvore{
	INFO info;  // informa��o que cada registro da �rvore ter�
	struct arvore *subd;   // Ponteiro para a sub-�rvore a direita 
	struct arvore *sube;   // Ponteiro para a sub-�rvore a esquerda
}ARVORE;

typedef struct feedback{
	int id; // id para os coment�rios
	char nome[30], email[50], comentario[400]; // os dados de cada feedback
	struct feedback* prox;	// ponteiro para o pr�ximo coment�rio
}FEEDBACK;
