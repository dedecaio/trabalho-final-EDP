#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"
#include "DataBase.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL;  // cria árvore
	CIDADE* cidades = NULL; // cria lista de cidades
		
	carregaArvore(&arvore); // carrega a árvore com os dados salvos em txt
	carregaListaCidades(&cidades); // carrega as cidades de mesmo modo
	zoey(); // chama as boas vindas de zoey
	int codigoResposta = percurso(arvore); // chama o percurso e armazena onde o usuário parou
	CIDADE* resposta = buscaCidades(cidades,codigoResposta); // cria uma nova lista de cidades apenas com as cidades que sejam de determinada categoria
	imprimeCidadesZoey(resposta); // imprime essas cidades
	coletaFeedback(); // chama função para coletar um feedback do usuário
	return 0;
}
