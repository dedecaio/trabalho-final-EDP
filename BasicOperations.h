#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inserir Conteudo na Arvore
void insereConteudo(ARVORE** arvore, int codigo, char conteudo[], int ePergunta){
	if(*arvore == NULL){
		ARVORE *no = ( ARVORE * ) malloc( sizeof( ARVORE ));
		if(no){
			no->info.codigo = codigo;
			no->info.ePergunta = ePergunta;
			strcpy(no->info.conteudo, conteudo);
			no->subd = NULL;
			no->sube = NULL;
			*arvore = no;
//			printf("\nRegistro inserido");
		}
	}else{
		if((*arvore)->info.codigo > codigo)
			insereConteudo(&(*arvore)->sube, codigo,conteudo,ePergunta);
		else if((*arvore)->info.codigo < codigo)
			insereConteudo(&(*arvore)->subd, codigo, conteudo,ePergunta);
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

int buscar(ARVORE* arvore, int codigo)  {
	if (arvore == NULL) {
		return -1;
	}
	
	if (codigo == arvore->info.codigo) {
		return 1;
	} else if (codigo < arvore->info.codigo) {
		return buscar(arvore->sube, codigo);
	} else {
		return buscar(arvore ->subd, codigo);
	}
}

void remove(ARVORE** arvore, int codigo){
	
	if (*arvore != NULL) {
		if (codigo < (*arvore)->info.codigo) {
			remove(&(*arvore)->sube, codigo);	
		} else if (codigo > (*arvore)->info.codigo) {
			remove(&(*arvore)->subd, codigo);
		} else {
			ARVORE *aux = *arvore;
			*arvore = NULL;
			free(aux);
			printf("\nRegistro excluido com sucesso!");
		}
	}
}

void insereCidade(CIDADE** cidades, int codigo, char nome[], char descricao[]){
	
	CIDADE *novo = (CIDADE*) malloc (sizeof(CIDADE));
	
	if( novo != NULL ){										// verifica se conseguiu alocar memória para o novo registro
        novo->codigo = codigo;					                           
        strcpy(novo->nome, nome);
        strcpy(novo->descricao, descricao);
        if( *cidades == NULL )                              // verifica se a lista está vazia, caso sim terá que ajustar o início da lista
            *cidades = novo;                                // insere o primeiro registro
        else{
             CIDADE *aux;                                // define ponteiro auxiliar             
             aux = *cidades;                             // posiciona ponteiro auxiliar na lista
             while( aux->prox != NULL )                // percorre a lista até encontrar o último registro
                    aux = aux->prox;
             aux->prox = novo;                         // último registro (nodo) aponta para o novo registro (novo)                     
        }               
    }else
        printf( "\n Lista cheia!" );
}

void imprimeCidades(CIDADE* cidades){
	if(cidades != NULL){
		while(cidades != NULL){
			printf("%s",cidades->nome);
			printf("\n%s",cidades->descricao);
			cidades = cidades->prox;
		}
	}
	
}
	
