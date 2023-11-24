#include <stdio.h>
#include <locale.h>
#include "estrutura.h"
#include "operacoes-basica.h"
#include "perguntasService.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	CIDADE* cidades = NULL;
	
	
	inserir(&arvore, 40, "Você gosta de natureza ou de áreas mais turísticas? (1 = turística | 2 = natureza)");
	inserir(&arvore, 60, "O que você mais deseja, curtir bem pertinho da natureza em um hotel ou viver perigosamente em uma floresta? (1 = hotel | 2 = no meio do mato mesmo)");
	inserir(&arvore, 20, "Quer ir no óbvio, conhecendo cidades mais urbanas, ou quer ir para o interior? (1 = urbana | 2 = interior)");
	inserir(&arvore, 30, "Quer ir em feiras ou quer conhecer as festas municipais? (1 = feiras | 2 = festas)");
	inserir(&arvore, 70, "Deseja acampar ou realizar uma trilha? (1 = acampar | 2 = trilha)");
	
//	imprime(arvore);
	int i=buscar (arvore, 25);
	printf ("%d", i);
	zoey();
	percurso(arvore);
	
	
	
	return 0;
}
