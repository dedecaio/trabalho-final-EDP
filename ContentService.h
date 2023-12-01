#include <stdio.h>

int percurso(ARVORE* arv){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int resposta;
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - %s ", arv->info.conteudo); 
	// se for �Pergunta = 1: 
	if (arv->info.ePergunta == 1){
		SetConsoleTextAttribute(hConsole, 7);
		scanf("%d",&resposta);
		if(resposta == 2)
			return percurso(arv->subd);
		else if(resposta == 1)
			return percurso(arv->sube);
		else{
		SetConsoleTextAttribute(hConsole, 13);
			printf("Zoey - Resposta inv�lida. Tente novamente\n");
			return percurso(arv);
		}
	}
	return arv->info.codigo;
 }

void zoey(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	printf("Zoey - Ol�, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para voc� viajar ok? :)");
	printf("\nZoey - S� preciso que responda algumas perguntinhas...");
	SetConsoleTextAttribute(hConsole, 7);
	printf("\nPressione enter para come�ar...");
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
