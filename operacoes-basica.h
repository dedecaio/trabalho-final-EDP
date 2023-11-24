#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirPergunta(ARVORE** arvore, int codigo, char conteudo[]){
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
			printf("Registro já inserido");
		
	}
}

void imprime(ARVORE* arv){
	if( arv != NULL ) {              // verifica se a raiz é diferente de vazio
		printf( "\n >> sube " );       //"de %i", aux->info.codigo );
		imprime( arv->sube ); // recursivo, segue pelo caminho da esquerda
		printf( "\n Código.....: %d", arv->info.codigo );
		printf( "\n Pergunta.....: %s", arv->info.conteudo );
		getchar();
		printf( "\n >> subd " );       //"de %i", aux->info.codigo );
		imprime( arv->subd ); // recursivo, segue pelo caminho da direita
	} else
		printf("\n Subárvore vazia!\n");
}


void remove(ARVORE** arvore, int codigo){}

int buscar(ARVORE* arvore, int codigo)  {
	if (arvore == NULL) {
		return -1;
	}
	
	if (codigo == arvore->info.codigo) {
		return arvore->info.codigo;
	} else if (codigo < arvore->info.codigo) {
		return buscar(arvore->sube, codigo);
	} else {
		return buscar(arvore ->subd, codigo);
	}
}
	
