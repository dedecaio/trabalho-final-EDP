#include <stdio.h>
#include <locale.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	CIDADE* cidades = NULL; // Lista de cidades
	
	
	insereConteudo(&arvore, 40, "Voc� gosta de natureza ou de �reas mais tur�sticas? (1 = tur�stica | 2 = natureza)",1); // � pergunta
	insereConteudo(&arvore, 60, "O que voc� mais deseja, curtir bem pertinho da natureza em um hotel ou viver perigosamente em uma floresta?"
	" (1 = hotel | 2 = no meio do mato mesmo)", 1);
	insereConteudo(&arvore, 20, "Quer ir no �bvio, conhecendo cidades mais urbanas, ou quer ir para o interior? (1 = urbana | 2 = interior)",1);
	insereConteudo(&arvore, 30, "Quer ir em feiras ou quer conhecer as festas municipais? (1 = feiras | 2 = festas)",1);
	insereConteudo(&arvore, 70, "Deseja acampar ou realizar uma trilha? (1 = acampar | 2 = trilha)",1);

	insereConteudo(&arvore, 80, "J� que gosta tanto de natureza e quer muito viver perigosamente em trilhas no meio do nada"
		"\n- Estou te recomendando cidades em que voc� vai amar visitar, de acordo com o que me disse:",0); // aqui insiro a resposta olha o 0 ali
		
		
		
		
	// Fun��o de inserir cidades na lista	
	insereCidade(&cidades, 80, "Cachoeira do Sul","Cachoeira do Sul � conhecida por suas atra��es naturais, "
	"incluindo o Ch�teau d�Eau, o Jardim Bot�nico e Zool�gico Municipal, a Ponte do Fandango, o Rio Jacu� e o"
	" Parque Municipal da Cultura. Esses locais oferecem oportunidades para camping e trilhas.");
	
	zoey();
	int codigoResposta = percurso(arvore); // a fun��o percurso retorna a folha onde ela parou
	printf("\n");
//	CIDADE* resposta = buscaCidades(cidades,codigoResposta)
//	imprimeCidades(resposta);
	
	imprimeCidades(cidades);
	remove(&arvore);
	imprime(arvore);
	
	return 0;
}
