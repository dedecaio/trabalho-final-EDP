 #include <stdio.h>


int percurso(ARVORE *arv){
	int resposta;
	printf("Zoey - %s ", arv->info.conteudo); 
	// se for éPergunta = 1: 
	if (arv->info.ePergunta == 1){
		scanf("%d",&resposta);
		if(resposta == 2)
			return percurso(arv->subd);
		else if(resposta == 1)
			return percurso(arv->sube);
		else{
			printf("Zoey - Resposta inválida. Tente novamente\n");
			return percurso(arv);
		}
	}
	return arv->info.codigo;
	
}

void zoey(){
	printf("Zoey - Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)");
	printf("\nZoey - Só preciso que responda algumas perguntinhas...");
	printf("\nPressione enter para começar...");
	getchar();
}
