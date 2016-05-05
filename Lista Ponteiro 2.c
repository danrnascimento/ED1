#include <stdio.h>
#include <stdlib.h>

int * preencher(int tamanho);
int * organizar(int tamanho, int *vetor);
void imprimir(int tamanho, int *vetor);

int main(){

    int tamanho;
    int *vetor;

    printf("Qual o tamanho do seu vetor? ");
    scanf("%d", &tamanho);

    system("clear");


    int *vetorPreenchido = preencher(tamanho);
    int *vetorOrganizado = organizar(tamanho, vetorPreenchido);

    system("clear");
    printf("\n\t Seu Vetor: \n\n\t");
    imprimir(tamanho, vetorOrganizado);
    printf("\n\n");
    return 0;
}

int * preencher(int tamanho){

    int *vetor = (int *) malloc( tamanho *  sizeof(int));

    int i;
    for(i = 0; i < tamanho; i++){
        printf("Digite o valor do item [ %d ]: ", i);
        scanf("%d", (vetor + i));
    }

    return vetor;

}

int * organizar(int tamanho, int *vetor){

    int *vetorOrganizado, aux, i, j;
    vetorOrganizado = vetor;

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho - 1 - i; j++){
            if(*(vetorOrganizado + j) > *(vetorOrganizado + j + 1)){
                aux = *(vetorOrganizado + j);
                *(vetorOrganizado + j) = *(vetorOrganizado + j + 1);
                *(vetorOrganizado + j + 1) = aux;
            }
        }
    }

    return vetorOrganizado;
}

void imprimir(int tamanho, int *vetor){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" [ %d ] ", *(vetor + i));
    }

}
