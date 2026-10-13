/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

•Exercício 2: Dadas as medidas dos catetos de um triângulo retângulo,
informe a medida da hipotenusa. [Dica: para calcular a raiz quadrada
use a função sqrt(), definida na biblioteca math.h].

*******************************************************************************/

#include <stdio.h>
#include <math.h>

//hipotenusa pelos catetos

void hipotenusa(){
    int c1, c2, h;
    
    printf("cateto 1: ");
    scanf("%d", &c1);
    printf("cateto 2: ");
    scanf("%d", &c2);
    
    h = sqrt(c1*c1 + c2*c2);
    
    printf("hipotenusa: %d", h);
    
}

//conversao fahrenheit para celsius

float operacao (float f) {
    return (f - 32) * (9/5);
}

void fah_to_cel () {
    float fah;
    float cel;
    
    printf("temperatura em fahrenheit: ");
    scanf("%f", &fah);
    
    printf("temperatura em celsius: ");
    cel = operacao(fah);
    printf("%f", cel);
}

int main()
{
    //fah_to_cel();
    hipotenusa();

    return 0;
}