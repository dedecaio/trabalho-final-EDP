#include <stdio.h>


void percurso(ARVORE *arv){
	int resposta;
	if (arv == NULL){
		printf("\nQue pena, parece que meus devs não colocaram nada no meu sistema. Desde já agradeço por me usar ;-;");
		return;
	}
	printf("- %s", arv->info.pergunta);
	scanf("%d",&resposta);
	if(resposta == 1)
		percurso(arv->subd);
	else if(resposta == 0)
		percurso(arv->sube);
	else{
		printf("Resposta inválida. Tente novamente");
		percurso(arv);
	}
}

void zoey(){
	printf("\n\n- Olá, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para você viajar ok? :)");
	printf("\n- Só preciso que responda algumas perguntinhas...");
	printf("\nPressione qualquer tecla para começar...");
	getchar();
}
