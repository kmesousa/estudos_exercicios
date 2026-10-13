#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1) Escreva um programa em C que permita inserir palavras, de >>> maneira ordenada e sem repetição <<<, em um vetor. O tamanho máximo do vetor é 100. O usuário é que deve informar as palavras que deseja inserir. Após cada inserção, o programa deve imprimir o estado atual do vetor.

o que significa "permita inserir palavras, de >>> maneira ordenada e sem repetição <<<" ?
o programa deve toda hora modificar o vetor para ordena-lo e chacar se nao ouve repeticao, ou isso é tarefa do usuário e o programa já assume que esses critérios estão sendo seguidos?

creio que o programa que deva fazer essa checagem

0. se vai caber

1. se a palavra ja exise no vetor
2. onde a palavra iria ser inserida

3. mover as outras palavras para inserir a nova
*/


void inserir_palavras () {
    const int tamMax = 100;
    char vetor[tamMax];
    int tamAtual = 0;

    //while
    char resposta[tamMax];
    int continuar = 1;
    int round = 0;

    while (continuar) {

        printf("================== INSERIR PALAVRAS ===========(%d)\n", round);
        printf("vetor atual: ");
        printf("há espaço para %d caracteres", tamMax - tamAtual);
        printf("---------------------------------------------\n");
        printf("digite uma palvra a ser inserida e ordena \n[0] para sair\n");
        printf(">> ");

        scanf(" %s", resposta);

        if (resposta[0]=='0') continuar = 0; break;

        //"limpar palavra" e verificar se é valida (nao é se tiver caracteres difernetes dos alfabeticos e dos especiais permitos, 1 palavra composta caso '-' e duas palavras caso ' ' ou ',')
        char especiais = {'-', ' ', ','};
        int qteEspeciais = strlen(especiais);



        //checar se a palavra cabe no vetor
        if (strlen(resposta) > tamMax - tamAtual) {
            printf("a palavra nao cabe no vetor");
            continue;
        }

        //checar se a palavra é repetida


        //inserir e reordenar vetor



        round++;

    }

}
/*2) Construído a solução (1), amplie para dar a capacidade de fazer busca sequencial de uma palavra no vetor. Permita que o usuário informe uma palavra, e busque a mesma no vetor. Caso exista, retorne informando que achou e em qual posição. Caso não exista, retorne informando que não achou.

3) Uma alternativa de algoritmo para a questão (2) consiste em fazer a busca binária no vetor. Implemente o programa para fazer buscas binárias de palavras no vetor gerado pela questão (1).

4) Com a finalidade de expandir a implementação da questão (1), inclua a funcionalidade de registrar a quantidade de repetições de uma palavra previamente inserida no vetor. Em cada inserção, esse contador é incrementado, por palavra. Após cada inserção, o programa deve imprimir o estado atual do vetor, que consiste na palavra e a quantidade de vezes que foi inserida. Não é permitido usar dois vetores.*/


int main () {
    inserir_palavras();
    return 0;
}