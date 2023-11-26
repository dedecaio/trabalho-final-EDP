#include <stdio.h>
#include <locale.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"
#include "DataBase.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	CIDADE* cidades = NULL; // Lista de cidades
		
	carregaArvore(&arvore);
//	
//	salvaArvore(arvore);
//	salvaListaCidades(cidades);
	carregaListaCidades(&cidades);
	zoey();
	int codigoResposta = percurso(arvore); // a função percurso retorna a folha onde ela parou
	printf("\n%d\n",codigoResposta);
//	CIDADE* resposta = buscaCidades(cidades,codigoResposta)
//	imprimeCidades(resposta);
	
	imprimeCidades(cidades);
	
	return 0;
}
