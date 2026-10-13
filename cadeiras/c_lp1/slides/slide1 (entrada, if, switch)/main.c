/* •Exercício 1: Dada uma temperatura em graus Fahrenheit, informe o
valor correspondente em graus Celsius. [Dica: C = (F – 32) ∗ (5 / 9)].*/

/*•Exercício 2: Dadas as medidas dos catetos de um triângulo retângulo,
informe a medida da hipotenusa. [Dica: para calcular a raiz quadrada
use a função sqrt(), definida na biblioteca math.h].*/

#include <stdio.h>

int converterFtC (int f) {

    float c = ((f - 32) * (5/9));
    return c;
}

void f_to_celsius () {

    int fah;
    printf("digite uma temperatura em fahrenheit: ");
    scanf("%d", &fah);
    //float cel = f_to_celsius(fah);
    float cel = (fah - 32) * (5/9);
    printf("%d F = %f C", fah, cel);
}

void verificar_triangulo () {
    //ja fiz essa no c online eu acho, mas perdi o código RIP
}

/*Usando o switch, crie uma calculadora simples (operações de +,-,*, e
/). O usuário digita uma expressão na forma valor1 oper valor2,
e o seu programa deve mostrar o resultado da expressão.*/

void calculadora() {
    float valor1, valor2, resultado;
    char oper;
    int valido = 1;

    printf("======== CALCULADORA SIMPLES ========\n");
    printf("digite a expressao na forma:\nvalor1 oper [+, -, *, /] valor2\n>> ");
    scanf(" %f %c %f", &valor1, &oper, &valor2);
    //printf("%f %c %f", valor1, oper, valor2); //vacilei pq tava usando &pra imprimir antes, nao precia!!

    switch (oper)
    {
    case '+': {
        resultado = valor1 + valor2;
        break;
    }
    case '-': {
        resultado = valor1 - valor2;
        break;
    }
    case '*': {
        resultado = valor1 * valor2;
        break;
    }
    case '/': {
        if (valor2 == 0) {
            resultado = 0;
            valido = 0;
        }
        else {
            resultado = valor1 / valor2;
        }

    }
    default:
        break;
    }

    if (!valido) {
        printf("operacao invalida.\n");
    }
    else {
        printf("%.2f %c %.2f = %.2f\n", valor1, oper, valor2, resultado);
    }

}

int main () {
    calculadora();
    return 0;
}