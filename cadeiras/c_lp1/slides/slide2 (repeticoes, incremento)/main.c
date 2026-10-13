//comandos de repetição, incremento, decremento

#include <stdio.h>
#include <math.h>

//calcular fatorial de um dado numero
void fatorial () {
    int num;
    int fat;

    //entrada
    printf("======== FATORIAL ==========\n");
    printf("numero inteiro = ");
    scanf(" %d", &num);

    //calculo e impressao
    fat = num;

    printf("%d" , num);

    for (int c = num - 1; c > 0; c--) {
        fat *= c;
        printf(" * %d", c);
    }

    printf(" = %d", fat);
    //acho q ficou legal

}

//padrao
/*exemplo:
n = impar

n = 5
*****
 ***
  *

esse ficaria mais legal, mas nao sei como faria esses espaços, sdds do .center() RIP python
nossa pera da de fazer sim, só seria mais chatin;
*/
void padrao_piramide () {
    int num;
    int blank = 0;

    //entrada
    printf("======== PADRAO PIRAMIDE ==========\n");
    printf("numero inteiro impar = ");
    scanf(" %d", &num);

    //imprimir padrao
    if (num % 2 == 0) {
        printf("digite um numero impar!\n");
    }
    else {
        for (int c = num; c > 0; c-=2) {
            blank++; //ou blank = (num - c) / 2

            //imprimir espaços a esquerda
            for (int b = 0; b < blank; b++) {
                printf(" ");
            }
            //imprimir pontinhos da piramide
            for (int i = 0; i < c; i++) {
                printf("*");
            }
            //imprimir espaços a direita
            for (int b = 0; b < blank; b++) {
                printf(" ");
            }
            //quebrar linha
            printf("\n");
        }
        //eba deu certo!!
    }
}

int qte_digitos (int num) {
    //retorna qte de digitos de um numero
    //dica = x/10 aiiiiiiii
    int qte = 0;
    int c = num;

    while (c > 0) {
        c = c/10;
        qte ++;
    }
    //acho q vai dar certo, espero

    return qte;
}

int ordem_inversa (int num) {
    //dica = x%10 aiaiaiiaiaiaiai
    int inverso = 0;
    int atual;
    int qteDigitos = qte_digitos(num);

    for (int c = qteDigitos-1; c >= 0; c--) {
        atual = num%10;
        inverso += atual * (pow(10, c)); //poderia fazer isso com um for, mas vamo usar a biblioteca msm melhor
        num = num/10;
        //printf(" %d %d %d %d \n", atual, num, inverso, c);
    }

    return inverso;
}

int ocorrencias(int num, int digito) {
    int qte;
    int c;

    while (num > 0) {
        c = num%10;
        if (c == digito) qte++;
        num = num/10;
    }

    return qte;
}

void analisar_num () {
    int num;
    int digito;
    int qteDigitos, inverso, o;

    //entrada
    printf("======== ANALISAR NUMERO ==========\n");
    printf("numero inteiro: ");
    scanf(" %d", &num);
    printf("digito (0-9): ");
    scanf(" %d", &digito);

    //validacao
    if (digito > 9 || digito < 0) {
        printf("valores digitados invalidos!\n");
    }
    else {
        qteDigitos = qte_digitos(num);
        inverso = ordem_inversa(num);
        o = ocorrencias(num, digito);

        printf("-----------------------------------\n");
        printf("numero digitado = %d\n", num);
        printf("-----------------------------------\n");
        printf("quantidade de digitos: %d\n", qteDigitos);
        printf("ordem inversa: %d\n", inverso);
        printf("o digito %d aparece %d vezes\n", digito, o);
    }
}

//selecionar problema

void selecionar() {
    int opcao;
    int continuar = 1;
    int resposta = 0;

    while (continuar==1) {
        printf("======= SELECIONAR PROBLEMA ======\n");
        printf("[0] sair\n");
        printf("[1] fatorial\n");
        printf("[2] padrao piramide\n");
        printf("[3] analisar numero\n");

        printf("===================================\n");
        printf("selecione o problema:\n>> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1: {
                fatorial();
                break;
            }
            case 2: {
                padrao_piramide();
                break;
            }
            case 3: {
                analisar_num();
                break;
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

int main() {
    selecionar();
    return 0;
}