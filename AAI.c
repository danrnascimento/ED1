#include <stdio.h>
#include <stdlib.h>

/**
    @author Daniel Nascimento
*/

int equals(char *str1, char *str2);
int equalsIgnoreCase(char *str1, char *str2);
int length(char *str);
char *toUpperCase(char *str);
char *toLowerCase(char *str);

int main(){

    char pa[] = "Daniel Rocha";
    char pa2[] = "DANIEL";

    printf("\n%d", equals(pa,pa2));
    printf("\n%d", equalsIgnoreCase(pa,pa2));
    printf("\n%d", length(pa));

    printf("\n%s", toUpperCase(pa));
    printf("\n%s", toLowerCase(pa));


    return 0;
}

int equals(char *str1, char *str2){

    while((*str1 == *str2) && (*str1)){
        str1++;
        str2++;
    }

    if((*str1 == *str2) && (!*str1))
        return 1;
    else
        return 0;
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

    int igual = equals(auxChar1, auxChar2);

    if (igual)
        return 1;
    else
        return 0;

}

int length(char *str){

    int count = 0;

    while((*str)){
        str++;
        count++;
    }

    return count;

}
