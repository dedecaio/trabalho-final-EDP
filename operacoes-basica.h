#include <stdio.h>
#include <stdlib.h>

void inserir(ARVORE** arvore, int codigo){
	if(*arvore == NULL){
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE ));
		if(no){
			no->info.codigo = codigo;
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
			printf("\nRegistro inserido");
		}
	}else{
		if((*arvore)->info.codigo > codigo)
			inserir(&(*arvore)->sube, codigo);
		else if((*arvore)->info.codigo < codigo)
			inserir(&(*arvore)->subd, codigo);
		else
			printf("Registro j� inserido");
		
	}
}

void imprime(ARVORE* arv){
	if( arv != NULL ) {              // verifica se a raiz � diferente de vazio
		printf( "\n >> sube " );       //"de %i", aux->info.codigo );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n C�digo.....: %d", arv->info.codigo );
		getchar();
		printf( "\n >> subd " );       //"de %i", aux->info.codigo );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Sub�rvore vazia!\n");
}
