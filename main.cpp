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
	carregaListaCidades(&cidades);

//	salvaArvore(arvore); // Fun��o de salvar �rvore
//	salvaListaCidades(cidades); // Fun��o de salvar a lista de cidades
	zoey();
	int codigoResposta = percurso(arvore); // a fun��o percurso retorna a folha onde ela parou
	printf("\n%d\n",codigoResposta);
	CIDADE* resposta = buscaCidades(cidades,codigoResposta);
	imprimeCidades(resposta);
	
	imprimeCidades(cidades);
	
	return 0;
}
