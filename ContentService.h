int percurso(ARVORE* arv){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int resposta;
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - %s ", arv->info.conteudo); 
	// se for éPergunta = 1: 
	if (arv->info.ePergunta == 1){
		SetConsoleTextAttribute(hConsole, 7);
		scanf("%d",&resposta);
		if(resposta == 2)
			return percurso(arv->subd);
		else if(resposta == 1)
			return percurso(arv->sube);
		else{
		SetConsoleTextAttribute(hConsole, 13);
			printf("Zoey - Resposta inválida. Tente novamente\n");
			return percurso(arv);
		}
	}
	return arv->info.codigo;
 }

void zoey(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)");
	printf("\nZoey - Só preciso que responda algumas perguntinhas...");
	SetConsoleTextAttribute(hConsole, 7);
	printf("\nPressione enter para começar...");
	getchar();
}

void imprimeCidadesZoey(CIDADE* cidades){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n");
	if(cidades){
		while(cidades){
			SetConsoleTextAttribute(hConsole, 13);
			printf("Zoey - ");
			SetConsoleTextAttribute(hConsole, 6);
			printf("%s\n", cidades->nome);
			SetConsoleTextAttribute(hConsole, 13);	
			printf("Zoey - %s\n\n",cidades->descricao);
			cidades = cidades->prox;
			SetConsoleTextAttribute(hConsole, 7);	
		}
	}else{
		printf("Zoey - Ao que parece, estou sem cidades! ;-;");
	}
}

insereFeedback(char nome[], char email[], char descricao[]){
	FILE* arquivo = fopen("Comentarios.txt", "a");
	
	fprintf(arquivo,"\"%s\" || \"%s\" || \"%s\"\n",nome,email,descricao);
}

void coletaFeedback(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int resposta;
	SetConsoleTextAttribute(hConsole, 13);
	printf("\n\nZoey - Deseja deixar um comentário? (1 - Sim | 2 - Não) ");
	SetConsoleTextAttribute(hConsole, 7);
	scanf("%d", &resposta);
	SetConsoleTextAttribute(hConsole, 13);
	if(resposta == 1){
		char nome[30],email[50],descricao[400];
		printf("Zoey - Qual seu nome? ");
		SetConsoleTextAttribute(hConsole, 7);
		fflush(stdin);
		gets(nome);
		SetConsoleTextAttribute(hConsole, 13);
		printf("Zoey - Qual seu email? ");
		SetConsoleTextAttribute(hConsole, 7);
		fflush(stdin);
		gets(email);
		SetConsoleTextAttribute(hConsole, 13);
		printf("Zoey - Qual comentário deseja deixar? ");
		SetConsoleTextAttribute(hConsole, 7);
		fflush(stdin);
		gets(descricao);
		SetConsoleTextAttribute(hConsole, 13);
		
		insereFeedback(nome,email,descricao);
		
		printf("\nZoey - Obrigado por deixar seu feedback, meus criadores vão analisar com carinho! :)");
	}else if(resposta == 2){
		printf("Zoey - Tudo bem então. Até mais e boa viagem! :)");
	}else{
		printf("Zoey - Não entendi °-°");
	}
}
