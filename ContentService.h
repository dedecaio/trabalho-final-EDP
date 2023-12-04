int percurso(ARVORE* arv){  // fun��o respons�vel por realizar o percurso da Zoey
	int resposta;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	if (arv == NULL){
		printf("\nZoey - Infelizmente estou sem nada em meu sistema. Sinto muito por isso! 1-1");
		return -1;
	}
	
	printf("\nZoey - %s ", arv->info.conteudo);   // printa o conte�do do registro da �rvore
	printf("\n");
	// se for ePergunta = 1: 
	if (arv->info.ePergunta == 1){ 
		SetConsoleTextAttribute(hConsole, 7);  // cor branca
		scanf("%d",&resposta); // se for pergunta ent�o espera por uma resposta
		if(resposta == 2) // se for 2 vai para a direita
			return percurso(arv->subd);
		else if(resposta == 1) // se for 1 vai para a esquerda
			return percurso(arv->sube);
		else{ // se n�o for nenhum a zoey avisa que n�o entendeu e chama a fun��o de novo 
			SetConsoleTextAttribute(hConsole, 13); // cor lil�s
			printf("Zoey - N�o entendi. Tente novamente\n");
			return percurso(arv);
		}
	}
	return arv->info.codigo; // se for resposta ent�o retorna o c�digo de onde parou
 }

void zoey(){  // fun��o de boas vindas da Zoey
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - Ol�, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para voc� viajar ok? :)\n");
	printf("\nZoey - S� preciso que responda algumas perguntinhas...\n");
	SetConsoleTextAttribute(hConsole, 7);
	printf("\nPressione enter para come�ar...");
	getchar();
}

void imprimeCidadesZoey(CIDADE* cidades){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n");
	if(cidades){ // s� printa os dados se tiver cidade
		while(cidades){ // enquanto cidade for diferente de NULL imprime
			SetConsoleTextAttribute(hConsole, 13); // cor lil�s
			printf("Zoey - ");
			SetConsoleTextAttribute(hConsole, 6); // cor amarela
			printf("%s\n", cidades->nome);
			SetConsoleTextAttribute(hConsole, 13);	// cor lil�s novamente
			printf("Zoey - %s\n\n",cidades->descricao);
			cidades = cidades->prox; // percorre toda a lista
			SetConsoleTextAttribute(hConsole, 7);	// cor branca
		}
	}else{
		SetConsoleTextAttribute(hConsole, 13); // cor lil�s
		printf("Zoey - Ao que parece, estou sem cidades! :(");
	}
}

insereFeedback(char nome[], char email[], char descricao[]){ // fun��o que armazena o feedback em Comentarios.txt
	FILE* arquivo = fopen("Comentarios.txt", "a"); // abre ou cria o arquivo em modo de que ele escreve abaixo daquilo que ja tem
	
	fprintf(arquivo,"\"%s\" || \"%s\" || \"%s\"\n",nome,email,descricao);  // salva os dados
}

void coletaFeedback(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int resposta;
	SetConsoleTextAttribute(hConsole, 13); // cor lil�s
	printf("\n\nZoey - Deseja deixar um coment�rio? (1 - Sim | 2 - N�o)\n");
	SetConsoleTextAttribute(hConsole, 7); // cor branca
	scanf("%d", &resposta); // l� a resposta
	SetConsoleTextAttribute(hConsole, 13); // cor lil�s
	if(resposta == 1){ // se a pessoa quer responder ent�o:
		char nome[30],email[50],descricao[400]; // define var�aveis em que os dados do feedback ser�o salvos
		printf("Zoey - Qual seu nome? ");
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(nome); // l� o nome da pessoa
		SetConsoleTextAttribute(hConsole, 13); // cor lil�s
		printf("Zoey - Qual seu email? "); 
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(email); // l� o email
		SetConsoleTextAttribute(hConsole, 13); // cor lil�s
		printf("Zoey - Qual coment�rio deseja deixar? ");
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(descricao); // pega o coment�rio da pessoa
		SetConsoleTextAttribute(hConsole, 13); // cor lil�s
		
		insereFeedback(nome,email,descricao); // manda esses dados para a fun��o que ir� armazenar tudo
		
		printf("\nZoey - Obrigado por deixar seu feedback, meus criadores v�o analisar com carinho! Boa viagem!! :)");
	}else if(resposta == 2){  // se for n�o, n�o l� nada
		printf("Zoey - Tudo bem ent�o. At� mais e boa viagem! :)");
	}else{
		printf("Zoey - N�o entendi �-�"); // caso a resposta n�o seja nem 1 nem 2 ela pede para que responada de novo
		coletaFeedback();
	}
}
