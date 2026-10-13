#include <stdio.h>

void somar () {
    int n1, n2, soma;

    printf("=== SOMAR INTEIROS ===\n");
    printf("digite um inteiro: ");
    scanf("%d", &n1);
    printf("digite outro inteiro: ");
    scanf("%d", &n2);

    soma = n1 + n2;
    printf("%d + %d = %d", n1, n2, soma);
}

int soma () {
    int n1, n2, soma;

    printf("=== SOMAR INTEIROS ===\n");
    printf("digite um inteiro: ");
    scanf("%d", &n1);
    printf("digite outro inteiro: ");
    scanf("%d", &n2);

    soma = n1 + n2;
    return soma;
}

void somar_float () {

}

//funcao para pedir quantos numeros quiser???? retornar por lista e dps desenpacotas? mas n sei como fazer isso

int main () {

    somar();
    return 0;
}