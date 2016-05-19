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

    char *nome = (char *)malloc(100);
    gets(nome);
    int index = String.firstIndexOf(nome, ',');
    int length = String.length(nome);
    nome = String.substring(nome, index, length);

    printf("%s ==== %d",nome, String.length(nome));

}
