#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Struct.h"
#include "BasicOperations.h"
#include "ContentService.h"
#include "DataBase.h"

void insereCidadeDashboard(ARVORE* arv, CIDADE** cidades){  // função que coleta todos os dados para inserir na lista de cidades
	char nome[100], descricao[1000];
	int codigo;
	printf("Código: ");
	scanf("%d",&codigo); // lê código
	if(buscar(arv,codigo) == -1){ // verifica se o registro existe e não é uma pergunta
		printf("Nenhum Registro foi encontrado ou o Registro se configura como pergunta!");
		return;
	}
	printf("Nome: ");
	fflush(stdin);
	gets(nome); // lê nome
	printf("Descrição: ");
	fflush(stdin);
	gets(descricao); // lê descrição
    insereCidade(&(*cidades), codigo, nome, descricao); // insere
}
void insereArvoreDashboard(ARVORE** arvore){ // função que coleta todos os dados para inserir na árvore
	char conteudo[400];
	int ePergunta, codigo;
	printf("Código: ");
	scanf("%d", &codigo); // lê código
	printf("Conteúdo: ");
	fflush(stdin);
	gets(conteudo); // lê conteudo do registro
	printf("É pergunta? (1 - sim | 0 - não) ");
	scanf("%d",&ePergunta); // lê se é ou não pergunta
	while (ePergunta < 0 || ePergunta > 1){  // só permite 0 ou 1
		printf("Resposta inválida. É pergunta? (1 - sim | 0 - não) ");
		scanf("%d",&ePergunta); // lê se é ou não pergunta
	}
	insereConteudo(&(*arvore),codigo,conteudo,ePergunta); // insere tudo na árvore
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int option;
	ARVORE *arvore = NULL; // cria árvore
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
         printf( "\n [4] Remover Conteúdo                                 " );
		 printf( "\n [5] Imprimir Cidades                                 " ); 
         printf( "\n [6] Imprimir árvore                                  " );
         printf( "\n [7] Ver Feedback da galera                           " );
         printf( "\n [0] Sair do Menu                                     " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opção: " );
         fflush( stdin );
         scanf( "%i", &option ); // lê qual a opção do menu
         switch( option ) { 
            case 1: // inserir Cidade
				insereCidadeDashboard(arvore,&cidades);
                break;        
				                         
            case 2: // inserir conteúdo na árvore
            	insereArvoreDashboard(&arvore);
                break;
                
            case 3: // remover cidade por id
            	removeCidade(&cidades);
                break;                     
                
            case 4: // remover registro da árvore por código
                int codigo;
                printf("Código: ");
                scanf("%d",&codigo);
                removeArvore(&arvore, codigo);
                break;
                
            case 5: // imprime a lista de cidades
            	imprimeCidades(cidades);
                break;

            case 6: // imprime a árvore
				imprime(arvore);
                break;
                
            case 7: // imprime o feedback
            	imprimeFeedback(feedback);
            	break;
					                                
            case 0: // término do programa                                                 
                exit( 1 ); 
                break;
                
            default : // opção inválida
                printf( "\n Digite uma opção!" );
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

