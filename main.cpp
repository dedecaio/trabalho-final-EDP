#include <stdio.h>
#include <locale.h>
#include "estrutura.h"
#include "operacoes-baiscas.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	ARVORE* arvore = NULL; 
	
	inserir(&arvore, 12);
	inserir(&arvore, 22);
	inserir(&arvore, 6);
	inserir(&arvore, 8);
	inserir(&arvore, 20);
	
	imprime(arvore);
	
	return 0;
}
