#include <stdio.h>
#include <stdlib.h>

float **alocarMatrizDinamica(int linha, int coluna);
float **liberarMatrizDinamica(int linha, float **matriz);

int main(){

    int i,linhas, colunas,j;

    printf("Digite o numero de linhas da sua matriz: ");
    scanf("%d", &linhas);

    printf("Digite agora as colunas: ");
    scanf("%d", &colunas);

    system("clear");

	float **matriz = alocarMatrizDinamica(linhas,colunas);

	system("clear");

    printf("\n\tSUA MATRIZ: \n\n");

	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("\t[ %2.f ]", *(*(matriz + i) + j));
		}
		printf("\n\n");
	}

    return 0;
}


float **alocarMatrizDinamica(int linha, int coluna){

    float **matriz = (float**) malloc(linha * sizeof(float *));
    int i,j;

    for (i = 0; i < linha; i++){
        *(matriz + i) = (float*) malloc(coluna * sizeof(float));
    }

    for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			printf("Digite o valor da posicao[ %d ] [ %d ]: ", i, j);
			scanf("%f", &(*(*(matriz + i) + j)));
		}
		printf("\n");
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
