 #include <stdio.h>


int percurso(ARVORE *arv){
	int resposta;
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
	return arv->info.codigo;
	
}

void zoey(){
	printf("Zoey - Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)");
	printf("\nZoey - Só preciso que responda algumas perguntinhas...");
	printf("\nPressione qualquer tecla para começar...");
	getchar();
}
