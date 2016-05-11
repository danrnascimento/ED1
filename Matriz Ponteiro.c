#include <stdio.h>
#include <stdlib.h>

/**
    @author Daniel Rocha do Nascimento

*/

float **alocarMatrizDinamica(int linha, int coluna);
float **liberarMatrizDinamica(int linha, float **matriz);
float **juntarMatrizes(int linha, int coluna, float **matriz, float **matriz2);
float **preencherMatriz(int linha, int coluna, float **matriz);
void exibir(int linha, int coluna, float **matriz);

int main(){

    int i,linhas, colunas,j, opcao;
    float **matriz, **matriz2, **matriz3;
    int certo = 1;


    while(certo){

        printf("\tEscolha uma das opções: \n");
        printf("\n\t1 Para preencher e exibir uma matriz\n\t2 Para criar e exibir outra matriz");
        printf("\n\t3 Para Juntar e exibir as matrizes somadas\n\t4 Para Limpar\n\t5 Para Sair\n");

        printf("\n\tSua Opcao: ");

        scanf("%d", &opcao);


        switch(opcao){
            case 1:

                system("clear");
                printf("\n\n Os Valores escolhidos servirao como parametro para as proximas matrizes! \n\n\n");
                printf("Digite o numero de linhas da sua matriz: ");
                scanf("%d", &linhas);

                printf("Digite agora as colunas: ");
                scanf("%d", &colunas);

                printf("\n\n");

                matriz = alocarMatrizDinamica(linhas,colunas);
                matriz = preencherMatriz(linhas, colunas, matriz);

                system("clear");

                exibir(linhas, colunas, matriz);

                break;

            case 2:

                system("clear");

                matriz2 = alocarMatrizDinamica(linhas, colunas);
                matriz2 = preencherMatriz(linhas, colunas, matriz2);

                system("clear");

                exibir(linhas,colunas,matriz2);


                break;

            case 3:

                system("clear");

                //matriz3 = alocarMatrizDinamica(linhas3, colunas3);
                matriz3 = juntarMatrizes(linhas,colunas,matriz,matriz2);

                exibir(linhas,colunas,matriz3);

                break;

            case 4:


                system("clear");

                liberarMatrizDinamica(linhas, matriz);
                liberarMatrizDinamica(linhas, matriz2);
                liberarMatrizDinamica(linhas, matriz3);

                break;

            case 5:

                printf("\n\n\tObrigado!\n\n");
                certo = 0;
                break;
        }
    }


    return 0;
}


float **alocarMatrizDinamica(int linha, int coluna){

    float **matriz = (float**) malloc(linha * sizeof(float *));
    int i,j;

    for (i = 0; i < linha; i++){
        *(matriz + i) = (float*) malloc(coluna * sizeof(float));
    }

    return matriz;
}

float **liberarMatrizDinamica(int linha, float **matriz){

    int i;

    for(i = 0; i < linha; i++){
        free(*(matriz + i));
    }

    free(matriz);
}

float **juntarMatrizes(int linha, int coluna, float **matriz, float **matriz2){

    int i,j,k,l,m,n;
    float **matrizDestino;
    matrizDestino = alocarMatrizDinamica(linha,coluna);

	for (i = 0; i < linha; i++) {
		for (j = 0; j < coluna; j++) {
			*(*(matrizDestino + i) + j) = (*(*(matriz + i) + j) + *(*(matriz2 + i) + j));
		}
	}

	return matrizDestino;

}

float **preencherMatriz(int linha, int coluna, float **matriz){

    int i, j;

    for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			printf("Digite o valor da posicao[ %d ] [ %d ]: ", i, j);
			scanf("%f", &(*(*(matriz + i) + j)));
		}
		printf("\n");
	}

	return matriz;
}

void exibir(int linha, int coluna, float **matriz){

    int i, j;
    printf("\n\tSUA MATRIZ: \n\n");

	for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			printf("\t[ %2.f ]", *(*(matriz + i) + j));
		}
		printf("\n\n");
	}
}
