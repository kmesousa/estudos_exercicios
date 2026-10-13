#include <stdio.h>

//selecionar problema

void selecionar() {
    int opcao;
    int continuar = 1;
    int resposta = 0;

    while (continuar==1) {
        printf("======= SELECIONAR PROBLEMA ======\n");
        printf("[0] sair\n");

        printf("===================================\n");
        printf("selecione o problema:\n>> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
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
    selecionar();
    return 0;
}