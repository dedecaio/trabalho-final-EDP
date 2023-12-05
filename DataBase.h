void salvaDadosArvore(ARVORE* arv, FILE* arquivo){ // salvar os dados em txt da árvore
	fprintf(arquivo, "%d || \"%s\" || %d\n", arv->info.codigo, arv->info.conteudo, arv->info.ePergunta); // salva tudo do registro atual
	
	if(arv->subd != NULL) // verifica se sub-árvore direita tem algo, se sim salva também 
		salvaDadosArvore(arv->subd, arquivo);
		
	if(arv->sube != NULL) // verifica se sub-árvore esquerda tem algo, se sim salva também 
		salvaDadosArvore(arv->sube, arquivo);
}

void salvaArvore(ARVORE* arv){ // salvar a árvore
	FILE *arquivo; // cria um arquivo
	
	if(arv == NULL){ // não salva nada se a árvore esta vazia
		printf("Árvore vazia");
		return;
	}
    arquivo = fopen( "PerguntasZoey.txt", "w" ); // abre o arquivo em modo de escrever
    
    if( arquivo == NULL ){ // verifica se o arquivo foi criado corretamente
        printf( "\n Erro ao criar arquivo!" );
        return;
    }
    
    salvaDadosArvore(arv,arquivo); // salva os dados no arquivo
    fclose( arquivo ); // fecha o arquivo
}


void carregaArvore(ARVORE** arv){ // carrega dados
    FILE *arquivo = fopen("PerguntasZoey.txt", "r"); // abre o arquivo em modo de leitura
    
    if ( arquivo == NULL ){ // verifica se o arquivo foi aberto corretamente 
        printf( "\n Arquivo nao encontrado!" );
        return;
    }
    
    char linha[600], conteudo[400];
    int codigo, ePergunta;
    while( fgets(linha, sizeof(linha), arquivo) != NULL ){ // lê todas as linhas do arquivo e salva em 'linha'
        sscanf(linha, "%d || \"%[^\"]\" || %d", &codigo, conteudo, &ePergunta); // lê da string linha e separa cada variável
        insereConteudo(&(*arv), codigo, conteudo, ePergunta); // insere na árvore
    }
    fclose( arquivo ); // fecha o arquivo
}

void salvaDadosLista(CIDADE* cidades, FILE* arquivo){ // salva os dados da lista de cidades em txt
	while(cidades != NULL){ // percorre toda a lista
		fprintf(arquivo, "%d || \"%s\" || \"%s\"\n", cidades->codigo, cidades->nome,cidades->descricao); // salva os dados no txt
		cidades = cidades->prox;
	}
}

void salvaListaCidades(CIDADE* cidades){
	if(cidades == NULL){ // não deixa salvar se lista estiver vazia
		printf("Lista vazia");
		return;
	}
	FILE *arquivo = fopen( "Cidades.txt", "w" ); // abre arquivo em modo de escrever
	
    if( arquivo == NULL ){ // verifica se o arquivo foi criado corretamente
        printf( "\n Erro ao criar arquivo!" );
        return;
    }
    
    salvaDadosLista(cidades,arquivo); // chama a função para salvar os dados
    fclose( arquivo ); // fecha arquivo
}

void carregaListaCidades(CIDADE** cidades){ // carregar lista de cidades do txt
	FILE *arquivo = fopen("Cidades.txt","r"); // abre arquivo em modo de leitura
	if ( arquivo == NULL ){ // verifica se o arquivo foi aberto corretamente 
        printf( "\n Arquivo nao encontrado!" );
        return;
    }
    
    char linha[1000], nome[100], descricao[800];
    int codigo;
    while( fgets(linha, sizeof(linha), arquivo) != NULL ){ // lê todas as linhas do arquivo
        sscanf(linha, "%d || \"%[^\"]\" || \"%[^\"]\"", &codigo, nome, descricao); // lê os dados da linha
        insereCidade(&(*cidades), codigo, nome, descricao); // insere os dados na lista
    }
    fclose( arquivo ); // fecha arquivo
}

void carregaFeedback(FEEDBACK** feedback){ // função para carregar lista de feedbacks
	FILE *arquivo = fopen("Comentarios.txt","r"); // abre arquivo em modo de leitura
	if ( arquivo == NULL ){ // verifica se o arquivo foi aberto corretamente 
        printf( "\n Arquivo nao encontrado!" );
        return;
    }
    
	char linha[500], nome[30], email[50],comentario[400];
    while( fgets(linha, sizeof(linha), arquivo) != NULL ){ // lê todas as linhas do arquivo
        sscanf(linha, "\"%[^\"]\" || \"%[^\"]\" || \"%[^\"]\"", nome, email, comentario); // lê e separa os dados 
        insereFeedbackLista(&(*feedback), nome, email, comentario); // insere na lista
    }
    fclose( arquivo ); // fecha o arquivo
}
