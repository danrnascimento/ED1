#include <stdlib.h>
#include <stdio.h>
#include "MinhaString.h"
#include <string.h>


typedef struct{
    char nome[50];
    char endereco[50];
    char dataNascimento[100];
    char codigo[6];
} usuario;

int main(){

    int quantidadeUsuarios, i;
    printf("Quantos usuarios deseja cadastrar? ");
    scanf("%d", &quantidadeUsuarios);

    usuario user[quantidadeUsuarios];

    for(i = 0; i < quantidadeUsuarios; i++){

        printf("\n\n--------------\n\n");
        printf("\nEntre com o nome do usuario %d: ", i + 1);
        gets(user[i].nome);
        printf("\nEntre com o endereco do usuario %d: ", i + 1);
        gets(user[i].endereco);
        printf("\nEntre com a data de Nascimento do usuario %d: ", i + 1);
        gets(user[i].dataNascimento);

    }



}
