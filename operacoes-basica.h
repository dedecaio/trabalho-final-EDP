#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir(ARVORE** arvore, int codigo, char conteudo[]){
	if(*arvore == NULL){
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE ));
		if(no){
			no->info.codigo = codigo;
			strcpy(no->info.conteudo, conteudo);
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
//			printf("\nRegistro inserido");
		}
	}else{
		if((*arvore)->info.codigo > codigo)
			inserir(&(*arvore)->sube, codigo,conteudo);
		else if((*arvore)->info.codigo < codigo)
			inserir(&(*arvore)->subd, codigo, conteudo);
		else
			printf("Registro j� inserido");
		
	}
}

void imprime(ARVORE* arv){
	if( arv != NULL ) {              // verifica se a raiz � diferente de vazio
		printf( "\n >> sube " );       //"de %i", aux->info.codigo );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n C�digo.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.conteudo );
		getchar();
		printf( "\n >> subd " );       //"de %i", aux->info.codigo );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Sub�rvore vazia!\n");
}
