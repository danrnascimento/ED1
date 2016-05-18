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
    fflush(stdin);
    scanf("%d", &quantidadeUsuarios);

    usuario *user = (usuario *)malloc(quantidadeUsuarios * sizeof(usuario));

}
