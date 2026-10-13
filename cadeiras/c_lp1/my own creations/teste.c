#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void adivinhar_num () {
    //joguinho que vai gerar um numero aleatorio, informar o tamanho do numero
    //usuario vai tentar adivinhar qual numero é, só vale tentativas que contenham numeros com a qte de digitos do numero a ser adivinhado
    //programa vai retornar se os digitos do numero enviado estao no numero a ser adivinhado, se estao na posição certa
    //ou fim se o usuario acertar o numero

    int max, tam, chave;

    chave = rand() % max;

}

void leitor_dinamico () {
    char parcial[100];
    int num;
    int ehNum = 1;
    int max = 10, min = 0;

    printf("digite um numero (enter gerar aleatoriamente) \n>> ");
    //gera um valor aleatoriamente se apertar enter sem digitar nada, se digitar algum valor, ele vai ler o valor digitado
    scanf(" %c", parcial);
    if (parcial[0]=='/0') {
        //gerar aleatorio
        num = (rand () % max) - min + 1;
    }
    else {
        int i = 0;
        while(parcial[i] != '/0') {
            if (parcial[i] < '0' && parcial[i] > '9') ehNum = 0; break;
        }
    }

    if (!ehNum) num = parcial;



}

int main()
{

    srand(time(NULL));
    leitor_dinamico();
    printf("hello kme \n");
    system("pause");
    return 0;
}
