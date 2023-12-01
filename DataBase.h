#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


void salvaDadosArvore(ARVORE* arv, FILE* arquivo){
	fprintf(arquivo, "%d || \"%s\" || %d\n", arv->info.codigo, arv->info.conteudo, arv->info.ePergunta);
	
	if(arv->subd != NULL)
		salvaDadosArvore(arv->subd, arquivo);
		
	if(arv->sube != NULL)
		salvaDadosArvore(arv->sube, arquivo);
}

void salvaArvore(ARVORE* arv){
	FILE *arquivo;
	
	if(arv == NULL){
		printf("Árvore vazia");
		return;
	}
    arquivo = fopen( "PerguntasZoey.txt", "w" );
    
    if( arquivo == NULL ){                     // verifica se o arquivo foi criado corretamente
        printf( "\n Erro ao criar arquivo!" );
        return;
    }
    
    salvaDadosArvore(arv,arquivo);
    fclose( arquivo );
	
}


void carregaArvore(ARVORE** arv){
	setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("PerguntasZoey.txt", "r");
    
    if ( arquivo == NULL ){                    // verifica se o arquivo foi aberto corretamente 
        printf( "\n Arquivo nao encontrado!" );
        return;
    }
    
    char linha[600], conteudo[400];
    int codigo, ePergunta;
    while( fgets(linha, sizeof(linha), arquivo) != NULL ){
        sscanf(linha, "%d || \"%[^\"]\" || %d", &codigo, conteudo, &ePergunta);
        insereConteudo(&(*arv), codigo, conteudo, ePergunta);
    }
    fclose( arquivo );                         // fecha o arquivo
}

void salvaDadosLista(CIDADE* cidades, FILE* arquivo){
	while(cidades != NULL){
		fprintf(arquivo, "%d || \"%s\" || \"%s\"\n", cidades->codigo, cidades->nome,cidades->descricao);
		cidades = cidades->prox;
	}
}

void salvaListaCidades(CIDADE* cidades){
	FILE *arquivo;
	
    arquivo = fopen( "Cidades.txt", "w" );
    
    if( arquivo == NULL ){                     // verifica se o arquivo foi criado corretamente
        printf( "\n Erro ao criar arquivo!" );
        return;
    }
    
    salvaDadosLista(cidades,arquivo);
    fclose( arquivo );	
}

void carregaListaCidades(CIDADE** cidades){
	setlocale(LC_ALL, "Portuguese");
	FILE *arquivo = fopen("Cidades.txt","r");
	if ( arquivo == NULL ){                    // verifica se o arquivo foi aberto corretamente 
        printf( "\n Arquivo nao encontrado!" );
        return;
    }
    
    char linha[800], nome[50], descricao[600];
    int codigo;
    while( fgets(linha, sizeof(linha), arquivo) != NULL ){
        sscanf(linha, "%d || \"%[^\"]\" || \"%[^\"]\"", &codigo, nome, descricao);
        insereCidade(&(*cidades), codigo, nome, descricao);
    }
    fclose( arquivo );         
	
}


