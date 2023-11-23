#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir(ARVORE** arvore, int codigo, char pergunta[]){
	if(*arvore == NULL){
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE ));
		if(no){
			no->info.codigo = codigo;
			strcpy(no->info.pergunta, pergunta);
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
//			printf("\nRegistro inserido");
		}
	}else{
		if((*arvore)->info.codigo > codigo)
			inserir(&(*arvore)->sube, codigo,pergunta);
		else if((*arvore)->info.codigo < codigo)
			inserir(&(*arvore)->subd, codigo, pergunta);
		else
			printf("Registro já inserido");
		
	}
}

void imprime(ARVORE* arv){
	if( arv != NULL ) {              // verifica se a raiz é diferente de vazio
		printf( "\n >> sube " );       //"de %i", aux->info.codigo );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n Código.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.pergunta );
		getchar();
		printf( "\n >> subd " );       //"de %i", aux->info.codigo );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Subárvore vazia!\n");
}
void remove(ARVORE** arvore, int codigo){}
