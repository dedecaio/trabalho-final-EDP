#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "DataBase.h"

void insereCidadeDashboard(ARVORE* arv, CIDADE** cidades){
	char nome[50], descricao[600];
	int codigo;
	printf("C�digo: ");
	scanf("%d",&codigo);
	if(buscar(arv,codigo) == -1){
		printf("Nenhum registro com este c�digo existe na �rvore!");
		return;
	}
	printf("Nome: ");
	fflush(stdin);
	gets(nome);
	printf("Descri��o: ");
	fflush(stdin);
	gets(descricao);
    insereCidade(&(*cidades), codigo, nome, descricao);
}
void insereArvoreDashboard(ARVORE** arvore){
	char conteudo[400];
	int ePergunta, codigo;
	printf("C�digo: ");
	scanf("%d", &codigo);
	printf("Conte�do: ");
	fflush(stdin);
	gets(conteudo);
	printf("� pergunta? (1 - sim | 0 - n�o)");
	scanf("%d",&ePergunta);
	insereConteudo(&(*arvore),codigo,conteudo,ePergunta);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int option;
	ARVORE *arvore = NULL;
	CIDADE *cidades= NULL;
	
	carregaArvore(&arvore);
	carregaListaCidades(&cidades);
	while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Dashboard da Zoey - Menu                             " );
         printf( "\n [1] Incluir Cidade                                   " );
         printf( "\n [2] Incluir Pergunta                                 " );
         printf( "\n [3] Remover Cidade                                   " );
         printf( "\n [4] Remover Pergunta                                 " );
         printf( "\n [5] Editar Cidade                                    " );                           
         printf( "\n [6] Editar Pergunta                                  " );
		 printf( "\n [7] Imprime Cidades                                  " ); 
         printf( "\n [8] Imprime �rvore de Perguntas                      " );
         printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );
         scanf( "%i", &option );
         switch( option ) {
            case 1:
				insereCidadeDashboard(arvore,&cidades);
                break;                                 
            case 2:
            	insereArvoreDashboard(&arvore);
                break;
            case 3: 
            	removeCidade(&cidades);
                break;                     
                
            case 4:
                int codigo;
                printf("C�digo: ");
                scanf("%d",&codigo);
                removeArvore(&arvore, codigo);
                break;
                  
            case 5:
            	// nao tem
                break;
                                                                                                                   
            case 6:
				// nao tem
                break;

            case 7:
            	imprimeCidades(cidades);
                break;

            case 8:
				imprime(arvore);
                break;
					                                
            case 0: // t�rmino do programa                                                 
                exit( 1 ); 
                break;
                
            default : 
                printf( "\n Digite uma op��o!" );
                break;
        } // fim switch( op )
        
		salvaArvore(arvore);
		salvaListaCidades(cidades);
        printf("\n");
        system("pause");       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
	
	return 0;
}

