#include <stdio.h>

//ARRAYS

void rotate_array (int array[], int lenArray, int deslocation) {
}

/*Dado um array de números aleatórios, empurre todos os zeros de um determinado array para o
final do array. Por exemplo, se os arrays fornecidos forem {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0},
eles devem ser alterados para {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. A ordem de todos os outros
elementos deve ser a mesma.*/
void move_zeros (int array[], int arrayLen) {

}


//selecionar problema

void selecionar() {
    int opcao;
    int continuar = 1;
    int resposta = 0;

    while (continuar==1) {
        printf("======= SELECIONAR PROBLEMA ======\n");
        printf("[0] sair\n");
        printf("[1] rotacionar array \n");

        printf("===================================\n");
        printf("selecione o problema:\n>> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1: {
                rotacionar_array();
            }
            default: {
                printf("fim da execucao.\n");
                continuar = 0;
                break;
                }
        }
        if (continuar != 0) {
             printf("\n===================================\n");
             printf("digite [1] para continuar\n>>");
             scanf("%d", &resposta);
        }

        if (resposta != 1) {
            continuar = 0;
        }
        printf("\n\n");

    }

}

int main () {
    //selecionar();
    rotacionar_array();
    return 0;
}