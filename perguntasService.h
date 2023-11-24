 #include <stdio.h>


void percurso(ARVORE *arv){
	int resposta;
	if (arv == NULL){
		printf("\n- Que pena, parece que meus devs n�o colocaram nada no meu sistema. Desde j� agrade�o por me usar ;-;");
		return;
	}
	printf("- %s ", arv->info.conteudo);
	scanf("%d",&resposta);
	if(resposta == 2)
		percurso(arv->subd);
	else if(resposta == 1)
		percurso(arv->sube);
	else{
		printf("Resposta inv�lida. Tente novamente\n");
		percurso(arv);
	}
}

void zoey(){
	printf("\n\n- Ol�, sou sua Assistente Virtual Zoey, estou aqui para te auxiliar. Vou te ajudar a encontrar o lugar perfeito para voc� viajar ok? :)");
	printf("\n- S� preciso que responda algumas perguntinhas...");
	printf("\nPressione qualquer tecla para come�ar...");
	getchar();
}
