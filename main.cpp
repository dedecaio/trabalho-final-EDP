#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"
#include "DataBase.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	CIDADE* cidades = NULL;
		
	carregaArvore(&arvore);
	carregaListaCidades(&cidades);
	zoey();
	int codigoResposta = percurso(arvore);
	CIDADE* resposta = buscaCidades(cidades,codigoResposta);
	imprimeCidadesZoey(resposta);
	coletaFeedback();
	return 0;
}
