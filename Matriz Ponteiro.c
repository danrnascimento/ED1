#include <stdio.h>
#include <stdlib.h>

float **alocarMatrizDinamica(int linha, int coluna);
float **liberarMatrizDinamica(int linha, float **matriz);

int main(){

    int linhas, colunas;

    printf("Digite o numero de linhas da sua matriz: ");
    scanf("%d", &linhas);

    printf("Digite agora as colunas: ");
    scanf("%d", &colunas);


    return 0;
}


float **alocarMatrizDinamica(int linha, int coluna){

    int **matriz = (int**) malloc(linha * sizeof(int *));
    int i;

    for (i = 0; i < linha; i++){
        *(matriz ) = (int*) malloc(coluna * sizeof(int));
    }
}

float **liberarMatrizDinamica(int linha, float **matriz){

    int i;

    for(i = 0; i < linha; i++){
        free(*(matriz + i));
    }

    free(matriz);
}
