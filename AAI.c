#include <stdio.h>
#include <stdlib.h>
/**
    @author Daniel Nascimento
*/
int equals(char *str1, char *str2);
char *toUperCase(char *str);
char *toLowerCase(char *str);

int main(){

    char pa[] = "Daniel";
    char pa2[] = "Daniel";

    printf("%d", equals(pa,pa2));

    printf("\n%s", toUperCase(pa));
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

char *toUperCase(char *str){

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
