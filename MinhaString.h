#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    @author Daniel Nascimento
*/

int equals(char *str1, char *str2);
int equalsIgnoreCase(char *str1, char *str2);
int length(char *str);
int lastIndexOf(char *str, char caracter);
int firstIndexOf(char *str, char caracter);
char *toUpperCase(char *str);
char *toLowerCase(char *str);
char *substring(char *str, int posicaoInico, int posicaoFina);
char *replace(char *str, char velho, char novo);

struct{

    int (*length)(char[]);
    int (*equals)(char[],char[]);
    int (*equalsIgnoreCase)(char[],char[]);
    int (*lastIndexOf)(char[], char);
    int (*firstIndexOf)(char[], char);
    char *(*toUpperCase)(char[]);
    char *(*toLowerCase)(char[]);
    char *(*substring)(char[],int,int);
    char *(*replace)(char[],char,char);

}String = {

    .length = length,
    .equals = equals,
    .equalsIgnoreCase = equalsIgnoreCase,
    .lastIndexOf = lastIndexOf,
    .firstIndexOf = firstIndexOf,
    .toUpperCase = toUpperCase,
    .toLowerCase = toLowerCase,
    .substring = substring,
    .replace = replace

};
/*
int main(){

    char *nome = (char *)malloc(sizeof(char));
    printf("\nNome: ");
    gets(nome);
    printf("\nO tamanho é : %d", String.length(nome));
    char *nome2 = (char *)malloc(sizeof(char));
    printf("\nNome: ");
    gets(nome2);
    printf("\n é igual? : %d", String.equals(nome, nome2));
    printf("\n é igual? : %d", String.equalsIgnoreCase(nome, nome2));
    printf("\n é antes do espaco? : %d", String.lastIndexOf(nome, ' '));
    printf("\n é depois do espaco? : %d", String.firstIndexOf(nome, ' '));
    printf("\n Upper: %s", String.toUpperCase(nome2));
    printf("\n Lower: %s", String.toLowerCase(nome));

    free(nome);

    nome = (char *)malloc(sizeof(char));
    printf("\nNome: ");
    gets(nome);
    printf("\n\n\n\n\n\n Substring: %s", String.substring(nome, 0, 3));
    printf("\n\n\n\n\n\n Replace: %s", String.replace(nome, 'a', 'x'));

    return 0;
}
*/
int equals(char *str1, char *str2){

    while((*str1 == *str2) && (*str1)){
        str1++;
        str2++;
    }

    return *str1 == *str2 && !*str1 ? 1 : 0;

}

char *toUpperCase(char *str){

    char *aux = str;
    while(*aux != '\0'){
        if (*aux >= 'a' && *aux <= 'z'){
            *aux -= 32;
        }
        aux++;
    }

    return str;

}

char *toLowerCase(char *str){

    char *aux = str;
    while(*aux != '\0'){
        if (*aux >= 'A' && *aux <= 'Z'){
            *aux += 32;
        }
        aux++;
    }

    return str;

}

int equalsIgnoreCase(char *str1, char *str2){

    char *auxChar1 = toUpperCase(str1);
    char *auxChar2 = toUpperCase(str2);

    return equals(auxChar1, auxChar2) == 1 ? 1 : 0;

}

int length(char *str){

    int count = 0;

    while((*str)){
        str++;
        count++;
    }

    return count;

}

int lastIndexOf(char *str, char caracter){

    int tamanho = length(str);
    int i;

    for (i = 0; i < tamanho; i++){
        if(*str == caracter){
            return i - 1;
        }
        str++;
    }

}

int firstIndexOf(char *str, char caracter){

    int tamanho = length(str);
    int i;

    for (i = 0; i < tamanho; i++){
        if(*str == caracter){
            return i + 1;
        }
        str++;
    }
}

char *replace(char *str, char velho, char novo){

    int i = 0;
    int tamanho = length(str);

    for (i = 0; i < tamanho; i++){
        if(str[i] == velho){
            str[i] = novo;
        }
    }
    return str;
}

char *substring(char *str, int posicaoInicio, int posicaoFinal){

    char nomeAux[10];
    int i,j = 0;
    for(i = posicaoInicio; i < posicaoFinal; i++){
        nomeAux[j] = str[i];
        j++;
    }

    return nomeAux;

}

