#include <stdio.h>
#include <locale.h>
#include "estrutura.h"
#include "operacoes-basica.h"
#include "perguntasService.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	
	inserir(&arvore, 40, "Você gosta de natureza ou de áreas mais turísticas? (0 = turística | 1 = natureza)");
	inserir(&arvore, 60, "O que você mais deseja, curtir bem pertinho da natureza em um hotel ou viver perigosamente em uma floresta? (0 = hotel | 1 = no meio do mato mesmo)");
	inserir(&arvore, 20, "Quer ir no óbvio, conhecendo cidades mais urbanas, ou quer ir para o interior? (0 = urbana | 1 = interior)");
	inserir(&arvore, 30, "Quer ir em feiras ou quer conhecer as festas municipais? (0 = feiras | 1 = festas)");
	inserir(&arvore, 70, "Deseja acampar ou realizar uma trilha? (0 = acampar | 1 = trilha)");
	
//	imprime(arvore);
	zoey();
	percurso(arvore);
	
	
	
	return 0;
}
