/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

Fazer um programa em C que dado três valores A, B e C, verificar se eles
formam um triângulo ou não. Caso sim, informar se é triângulo equilátero,
isósceles ou escaleno.

Condição para ser triângulo: a soma do comprimento de dois lados deve ser
maior (ou igual) ao comprimento do terceiro lado.

•Tipos de triângulos:
• triângulo equilátero: todos os lados são iguais
• triângulo isósceles: dois lados iguais
• triângulo escaleno: todos os lados são diferentes

*******************************************************************************/

#include <stdio.h>

void classificar_triangulo () {
    int l1, l2, l3; //usando variaveis independentes
    int l[3]; //usando um vetor definido
    char *tipo;
    
    printf("==== CLASSIFICAR TRIANGULO ====\n");
    
    for (int i=0; i<3; i++) {
        printf("lado %d: ", i+1);
        scanf("%d", &l[i]);
    }
    
    if (l[0] + l[1] < l[2] || l[1] + l[2] < l[0] || l[2] + l[0] < l[1]) {
        printf("não se pode formar um triangulo");
    }
    else  {
    
        if (l[0]==l[1] && l[0]==l[2]) {
            tipo = "equilatero";
            printf("o triangulo é equilatero");
        }
        else if (l[0]!=l[1] && l[1]!=l[2] && l[2]!=l[0]) {
            tipo = "escaleno";
            printf("o triangulo é escaleno");
        }
        else {
            tipo = "isoceles";
            printf("o triangulo é isoceles");
        }
        //printf("o triangulo é %s", tipo); 
    }

}


int main()
{

    classificar_triangulo();
    return 0;
}