 #include <stdio.h>


void percurso(ARVORE *arv){
	int resposta;
	if (arv == NULL){
		printf("\nZoey - Que pena, parece que meus devs não colocaram nada no meu sistema. Desde já agradeço por me usar ;-;");
		return;
	}
	printf("Zoey - %s ", arv->info.conteudo); 
	// se for éPergunta = 1: 
	if (arv->info.ePergunta == 1){
		scanf("%d",&resposta);
		if(resposta == 2)
			percurso(arv->subd);
		else if(resposta == 1)
			percurso(arv->sube);
		else{
			printf("Zoey - Resposta inválida. Tente novamente\n");
			percurso(arv);
		}
	}
	// se nao for pergunta faz nada
	
}

void zoey(){
	printf("Zoey - Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)");
	printf("\nZoey - Só preciso que responda algumas perguntinhas...");
	printf("\nPressione qualquer tecla para começar...");
	getchar();
}
