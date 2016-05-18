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

// struct String
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

//funcao para verificar se e igual
int equals(char *str1, char *str2){

    while((*str1 == *str2) && (*str1)){
        str1++;
        str2++;
    }

    return *str1 == *str2 && !*str1 ? 1 : 0;

}

//colocando tudo em maiusculo
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

//colocando tudo em minusculo
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

//comparando ignorando case
int equalsIgnoreCase(char *str1, char *str2){

    char *auxChar1 = toUpperCase(str1);
    char *auxChar2 = toUpperCase(str2);

    return equals(auxChar1, auxChar2) == 1 ? 1 : 0;

}

//veificar tamanho da string
int length(char *str){

    int count = 0;

    while((*str)){
        str++;
        count++;
    }

    return count;

}

//mostrar ultimo index antes do caracter desejado
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

//mostrar primeiro indice depois do caracter desejado
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

//trocar caracteres antigos por novos
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

//selecionar parte da Sring
char *substring(char *str, int posicaoInicio, int posicaoFinal){

    char nomeAux[100];
    int i,j = 0;
    for(i = posicaoInicio; i < posicaoFinal; i++){
        nomeAux[j] = str[i];
        j++;
    }

    return nomeAux;

}

