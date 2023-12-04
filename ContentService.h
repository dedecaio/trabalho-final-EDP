int percurso(ARVORE* arv){  // função responsável por realizar o percurso da Zoey
	int resposta;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	if (arv == NULL){
		printf("\nZoey - Infelizmente estou sem nada em meu sistema. Sinto muito por isso! 1-1");
		return -1;
	}
	
	printf("\nZoey - %s ", arv->info.conteudo);   // printa o conteúdo do registro da árvore
	printf("\n");
	// se for ePergunta = 1: 
	if (arv->info.ePergunta == 1){ 
		SetConsoleTextAttribute(hConsole, 7);  // cor branca
		scanf("%d",&resposta); // se for pergunta então espera por uma resposta
		if(resposta == 2) // se for 2 vai para a direita
			return percurso(arv->subd);
		else if(resposta == 1) // se for 1 vai para a esquerda
			return percurso(arv->sube);
		else{ // se não for nenhum a zoey avisa que não entendeu e chama a função de novo 
			SetConsoleTextAttribute(hConsole, 13); // cor lilás
			printf("Zoey - Não entendi. Tente novamente\n");
			return percurso(arv);
		}
	}
	return arv->info.codigo; // se for resposta então retorna o código de onde parou
 }

void zoey(){  // função de boas vindas da Zoey
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)\n");
	printf("\nZoey - Só preciso que responda algumas perguntinhas...\n");
	SetConsoleTextAttribute(hConsole, 7);
	printf("\nPressione enter para começar...");
	getchar();
}

void imprimeCidadesZoey(CIDADE* cidades){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n");
	if(cidades){ // só printa os dados se tiver cidade
		while(cidades){ // enquanto cidade for diferente de NULL imprime
			SetConsoleTextAttribute(hConsole, 13); // cor lilás
			printf("Zoey - ");
			SetConsoleTextAttribute(hConsole, 6); // cor amarela
			printf("%s\n", cidades->nome);
			SetConsoleTextAttribute(hConsole, 13);	// cor lilás novamente
			printf("Zoey - %s\n\n",cidades->descricao);
			cidades = cidades->prox; // percorre toda a lista
			SetConsoleTextAttribute(hConsole, 7);	// cor branca
		}
	}else{
		SetConsoleTextAttribute(hConsole, 13); // cor lilás
		printf("Zoey - Ao que parece, estou sem cidades! :(");
	}
}

insereFeedback(char nome[], char email[], char descricao[]){ // função que armazena o feedback em Comentarios.txt
	FILE* arquivo = fopen("Comentarios.txt", "a"); // abre ou cria o arquivo em modo de que ele escreve abaixo daquilo que ja tem
	
	fprintf(arquivo,"\"%s\" || \"%s\" || \"%s\"\n",nome,email,descricao);  // salva os dados
}

void coletaFeedback(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int resposta;
	SetConsoleTextAttribute(hConsole, 13); // cor lilás
	printf("\n\nZoey - Deseja deixar um comentário? (1 - Sim | 2 - Não)\n");
	SetConsoleTextAttribute(hConsole, 7); // cor branca
	scanf("%d", &resposta); // lê a resposta
	SetConsoleTextAttribute(hConsole, 13); // cor lilás
	if(resposta == 1){ // se a pessoa quer responder então:
		char nome[30],email[50],descricao[400]; // define varíaveis em que os dados do feedback serão salvos
		printf("Zoey - Qual seu nome? ");
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(nome); // lê o nome da pessoa
		SetConsoleTextAttribute(hConsole, 13); // cor lilás
		printf("Zoey - Qual seu email? "); 
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(email); // lê o email
		SetConsoleTextAttribute(hConsole, 13); // cor lilás
		printf("Zoey - Qual comentário deseja deixar? ");
		SetConsoleTextAttribute(hConsole, 7); // cor branca
		fflush(stdin);
		gets(descricao); // pega o comentário da pessoa
		SetConsoleTextAttribute(hConsole, 13); // cor lilás
		
		insereFeedback(nome,email,descricao); // manda esses dados para a função que irá armazenar tudo
		
		printf("\nZoey - Obrigado por deixar seu feedback, meus criadores vão analisar com carinho! Boa viagem!! :)");
	}else if(resposta == 2){  // se for não, não lê nada
		printf("Zoey - Tudo bem então. Até mais e boa viagem! :)");
	}else{
		printf("Zoey - Não entendi °-°"); // caso a resposta não seja nem 1 nem 2 ela pede para que responada de novo
		coletaFeedback();
	}
}
