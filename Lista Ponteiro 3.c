#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
}Produto;

Produto *funcaoAlocar(){

    int n;
    Produto *pInicial;


    printf("Digite a quantidade de Produtos: ");
    scanf("%d", &n);

    pInicial = (Produto *)malloc(n * sizeof(Produto));
    if(pInicial == NULL){
        printf("Não foi possivel alocar");
        exit(1);
    }

    return pInicial;

}

Produto *cadastro(Produto *pInicial){

    Produto *aux;
    aux = pInicial;
    int i = 1;

    while(pInicial){

        while((*aux).nome != NULL)
            printf("Digite a Descricao %d : ", i);
            gets((*aux).nome);

        while((*aux).codigo >= 0 && (*aux).codigo <= 50)
            printf("Digite o codigo %d : ", i);
            scanf("%d", &(*aux).codigo);

        while((*aux).preco >= 0)
            printf("Digite o preco %d : ", i);
            scanf("%f", &(*aux).preco);

        while((*aux).quantidade >= 0)
            printf("Digite a quantidade %d : ", i);
            scanf("%d", &(*aux).quantidade);

        i++;
        aux++;
    }

    return pInicial;
}

void listarProdutoSemEstoque(Produto *pInicial){

    int i;
    Produto *aux;
    aux = pInicial;

    while()

}

int main(){

    return 0;
}
