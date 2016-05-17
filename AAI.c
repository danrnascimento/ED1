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
char *replace(char *str, char velho, char novo);

struct usuario{
    char nome[100];
    char endereco[100];
    char dataNascimento[100];
};

int main(){

    struct usuario *user;

    user = (usuario *)malloc(3 * sizeof(usuario));
    int i;

    for(i = 0; i < 3; i++){

        printf("\n\n------\n\n");
        printf("Nome: %s", user.nome);
        printf("Endereco: %s", user.endereco);
        printf("dataNascimento: %s",user.dataNascimento);

        user++;
    }

    return 0;
}

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



}

