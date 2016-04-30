#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int receberNumeros(){
    int quantidade;
    printf("\n\tDigite quantos números terá seu vetor?   ");
    scanf("%d", &quantidade);
    return quantidade;
}

void entrarValores(int *vetor, int quantidade){
    int i;

    for(i = 0; i < quantidade; i++){
        printf("\tDigite o %d numero:  ", i);
        scanf("%d", vetor);
        vetor++;
    }
}

void ordernar(int *vetor, int quantidade);
void maior(int *vetor, int quantidade);
void menor(int *vetor, int quantidade);
void meio(int *vetor, int quantidade);
void achar(int *vetor, int quantidade, int numero);
void contar(int *vetor, int quantidade, int numero);
void inverter(int *vetor, int quantidade);
void junta2(int *vetor, int quantidade, int organizar);


//menu
int main(){
    int true = 1;

    int quantidade = receberNumeros();
    int vetor[quantidade];
    int numero;
    entrarValores(vetor, quantidade);


    while(true){
        int opcao;
        printf("\n\n\n\t===! Escolha uma das opções !===\n\n\t1 Para Ordenar\n\t2 Para mostrar o maior");
        printf("\n\t3 Para mostrar o menor\n\t4 Para mostrar os elementos do meio\n\t5 Para Verificar Valor");
        printf("\n\t6 Para contar os Valores\n\t7 Para inverter\n\t8 Para juntar mais uma string\n\t9 Para Juntar e Organizar");
        printf("\n\tQualquer outro numero para sair");
        printf("\n\n\tQual sua opção?  ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                ordernar(vetor, quantidade);
                break;
            case 2:
                maior(vetor, quantidade);
                break;
            case 3:
                menor(vetor,quantidade);
                break;
            case 4:
                meio(vetor, quantidade);
                break;
            case 5:
                printf("\n\tQue número deseja procurar? ");
                scanf("%d", &numero);
                achar(vetor,quantidade,numero);
                break;
            case 6:
                printf("\n\tQue número deseja procurar? ");
                scanf("%d", &numero);
                contar(vetor,quantidade,numero);
                break;
            case 7:
                inverter(vetor, quantidade);
                break;
            case 8:
                junta2(vetor, quantidade, 0);
                break;
            case 9:
                junta2(vetor, quantidade, 1);
                break;
            default:
                printf("\n\n\tSo long and thanks for all the fish!\n\n");
                true = 0;
                break;

        }
    }

    return 0;
}

//exibir na ordem digitada
void ordernar(int *vetor, int quantidade){

    int i,*aux;

    printf("\n");
    for(i = 0; i < quantidade; i++){
        printf("\t[ %d ]", *(vetor + i));
    }

}

//mostrar apenas o maior
void maior(int *vetor, int quantidade){

    int i,maior;
    maior = *vetor;
    for (i = 0; i < quantidade; i++){
        if (*(vetor + i) > maior){
            maior = *(vetor + i);
        }
    }

    printf("\n\t[ %d ]", maior);

}


//mostrar apenas o menor
void menor(int *vetor, int quantidade){

    int i,menor;
    menor = *vetor;
    for (i = 0; i < quantidade; i++){
        if (*(vetor + i) < menor){
            menor = *(vetor + i);
        }
    }
    printf("\n\t[ %d ]", menor);

}

//mostrar apenas o meio
void meio(int *vetor, int quantidade){
    int i;

    //igonora a posição 0 e ignora a ultima posição
    for(i = 1; i < (quantidade - 1); i++){
        printf("\t[ %d ]", *(vetor + i));
    }
}

//verificar se o numero esta no vetor
void achar(int *vetor, int quantidade, int numero){

    int i, achou;
    achou = 0;

    for(i = 0; i < quantidade; i++){
        if(*(vetor + i) == numero){
            achou = 1;
        }
    }

    if (achou == 1){
        printf("\n\tEste numero está presente!\n");
    }
    else{
        printf("\n\tEste numero não está presente!\n");
    }

}
//contar as vezes que o numero está no vetor
void contar(int *vetor, int quantidade, int numero){

    int i, achou;
    achou = 0;

    for(i = 0; i < quantidade; i++){
        if(*(vetor + i) == numero){
            achou++;
        }
    }

    printf("\n\tNumero de vezes que aparece: %d", achou);

}

//Inverter a ordem digitada
void inverter(int *vetor, int quantidade){
    int i,j;

    printf("\n");
    for(i = quantidade - 1  ; i >= 0; i--){
        printf("\t[ %d ]", *(vetor + i));
    }
}

void junta2(int *vetor, int quantidade, int organizar){

    int i,j,k,l,quantidade2,*aux, aux1;

    //-----------------------------------------

    //entrar com o segundo vetor

    quantidade2 = receberNumeros();
    int vetor2[quantidade2];
    entrarValores(vetor2, quantidade2);
    aux = vetor2;

    //-------------------------------------------

    //tamanho final
    int quantidade3 = quantidade + quantidade2;

    int vetor3[quantidade3]; //criar terceiro vetor

    //-------------------------------------------

    //popular o terceiro com o primeiro vetor
    for(i = 0; i < quantidade; i++){
        *(vetor3 + i) = *(vetor + i);
    }
    //popular o terceiro vetor com o segundo
    for(i = quantidade; i < quantidade3; i++){
        *(vetor3 + i) = *aux;
        aux++;
    }

    //verificar se é para organizar ou não
    if (organizar == 1){
        for(j = 0; j < quantidade3; j++){
            for(l = 0; l < quantidade3 - 1 -j; l++){
                if(*(vetor3 + l) > *(vetor3 + l + 1)){ //vetor3[l] > vetor [l + 1]?
                    aux1 = *(vetor3 + l);//aux = vetor3[l]
                    *(vetor3 + l) = *(vetor3 + l + 1);//vetor3[l] = vetor3[l + 1]
                    *(vetor3 + l + 1) = aux1;//vetor[l + 1] = aux
                }
            }
        }
        printf("\n");
        for(j = 0; j < quantidade3; j++){
            printf("\t[ %d ]", *(vetor3 + j));
        }
        printf("\n");
    }else{
        printf("\n");
        for(j = 0; j < quantidade3; j++){
            printf("\t[ %d ]", *(vetor3 + j));
        }
        printf("\n");
    }


}
