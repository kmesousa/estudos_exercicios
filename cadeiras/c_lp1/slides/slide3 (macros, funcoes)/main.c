#include <stdio.h>

/*Em um dado de 10 lados, cada lado possui 10% de chance de ser sorteado.
Crie um programa em C para simular um dado viciado de 10 lados, em que:
○ O lado 1 possui 30% de chance de ser sorteado
○ O lado 5 possui 2 vezes mais chances de ser sorteado que o lado 3*/

/*Crie uma função recursiva que leia um inteiro n, e indique quantos dígitos
possui n.
○ obs.: utilize uma variável estática como contador.*/

int funcoes (int argc, char** argv){
    printf("Voce entrou com %d argumentos\n", argc);
    for (int i = 0; i < argc; ++i)
    printf("%s \t ", argv[i]);
}

int main () {
    //funcoes(4, ("amar", "rezer", "b", "c")); //acho q eu n sei como usar isso
    return 0;
}