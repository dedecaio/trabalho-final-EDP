#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"
#include "DataBase.h"

void insereCidadeDashboard(ARVORE* arv, CIDADE** cidades){  // fun��o que coleta todos os dados para inserir na lista de cidades
	char nome[100], descricao[1000];
	int codigo;
	printf("C�digo: ");
	scanf("%d",&codigo); // l� c�digo
	if(buscar(arv,codigo) == -1){ // verifica se o registro existe e n�o � uma pergunta
		printf("Nenhum Registro foi encontrado ou o Registro se configura como pergunta!");
		return;
	}
	printf("Nome: ");
	fflush(stdin);
	gets(nome); // l� nome
	printf("Descri��o: ");
	fflush(stdin);
	gets(descricao); // l� descri��o
    insereCidade(&(*cidades), codigo, nome, descricao); // insere
}
void insereArvoreDashboard(ARVORE** arvore){ // fun��o que coleta todos os dados para inserir na �rvore
	char conteudo[400];
	int ePergunta, codigo;
	printf("C�digo: ");
	scanf("%d", &codigo); // l� c�digo
	printf("Conte�do: ");
	fflush(stdin);
	gets(conteudo); // l� conteudo do registro
	printf("� pergunta? (1 - sim | 0 - n�o) ");
	scanf("%d",&ePergunta); // l� se � ou n�o pergunta
	while (ePergunta < 0 || ePergunta > 1){  // s� permite 0 ou 1
		printf("Resposta inv�lida. � pergunta? (1 - sim | 0 - n�o) ");
		scanf("%d",&ePergunta); // l� se � ou n�o pergunta
	}
	insereConteudo(&(*arvore),codigo,conteudo,ePergunta); // insere tudo na �rvore
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int option;
	ARVORE *arvore = NULL; // cria �rvore
	CIDADE *cidades = NULL; // cria lista de cidades
	FEEDBACK *feedback = NULL; // cria lista de feedbacks
	
	// carrega os dados do txt
	carregaArvore(&arvore); 
	carregaListaCidades(&cidades);
	carregaFeedback(&feedback);
	// 
	
	// printa menu
	while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Dashboard da Zoey - Menu                             " );
         printf( "\n [1] Inserir Cidade                                   " );
         printf( "\n [2] Inserir Pergunta                                 " );
         printf( "\n [3] Remover Cidade                                   " );
         printf( "\n [4] Remover Conte�do                                 " );
		 printf( "\n [5] Imprimir Cidades                                 " ); 
         printf( "\n [6] Imprimir �rvore                                  " );
         printf( "\n [7] Ver Feedback da galera                           " );
         printf( "\n [0] Sair do Menu                                     " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );
         scanf( "%i", &option ); // l� qual a op��o do menu
         switch( option ) { 
            case 1: // inserir Cidade
				insereCidadeDashboard(arvore,&cidades);
                break;        
				                         
            case 2: // inserir conte�do na �rvore
            	insereArvoreDashboard(&arvore);
                break;
                
            case 3: // remover cidade por id
            	removeCidade(&cidades);
                break;                     
                
            case 4: // remover registro da �rvore por c�digo
                int codigo;
                printf("C�digo: ");
                scanf("%d",&codigo);
                removeArvore(&arvore, codigo);
                break;
                
            case 5: // imprime a lista de cidades
            	imprimeCidades(cidades);
                break;

            case 6: // imprime a �rvore
				imprime(arvore);
                break;
                
            case 7: // imprime o feedback
            	imprimeFeedback(feedback);
            	break;
					                                
            case 0: // t�rmino do programa                                                 
                exit( 1 ); 
                break;
                
            default : // op��o inv�lida
                printf( "\n Digite uma op��o!" );
                break;
        }
        
        //salva os dados 
		salvaArvore(arvore);
		salvaListaCidades(cidades);
		//
        printf("\n");
        system("pause");       // parada da tela
        system( "cls" ); // limpar tela
    }
	
	return 0;
}

