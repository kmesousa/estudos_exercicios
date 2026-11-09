#include <stdio.h>
#include <stdlib.h>
#include "02.c"

/*Desafio 3.1: Vetor dinâmico
Leia n do teclado, aloque n inteiros com malloc, preencha com os quadrados (1, 4, 9...), imprima e libere. Sempre teste se o malloc retornou NULL.*/

int * alocar_vetor(int n) {
    if (n <= 0) return NULL;
    int *v;
    //while (v == NULL) v = (int *) malloc( n*sizeof(int)); //nao faça assim kme, precisaria ficar liberando memoria antes, e também não é bom deixar tentando pra sempre
    v = (int *) malloc( n*sizeof(int));
    if (v == NULL) return NULL;
    return v;
}

void preencher_quadrados (int *v, int n) {
    for (int i = 1; i < n+1; i++) {
        *v++ = (i)*(i);
    }
}

/*Desafio 3.2: Retornar memória alocada
Escreva int *cria_sequencia(int n) que aloca, preenche com 0..n-1 e retorna o ponteiro. Quem libera? Onde? Escreva a resposta como comentário.*/

void preencher_sequencia (int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
}

int *cria_sequencia (int n) {
    int *v = alocar_vetor(n);
    preencher_sequencia(v, n);
    return v;
}

/*Desafio 3.3: Caçando bugs
Este código tem 3 erros de memória. Ache todos antes de compilar:

Depois rode com -fsanitize=address e confira se você achou os mesmos que a ferramenta.
*/

void achar_erros () {
    int *v = malloc(5 * sizeof(int));
    for (int i = 0; i <= 5; i++) v[i] = i;
    free(v);  // libera sendo que vai ser usado dnv dps
    printf("%d\n", v[2]); //ta querendo acessar dps de liberar o vetor;
    free(v); //liberando duas vezes
}

int main () {

    printf("======== VETOR DINAMICO ========\n");

    int n;
    int *v;

    printf("digite o tamanho do vetor: ");
    scanf(" %d", &n);

    v = alocar_vetor(n);
    preencher_quadrados(v, n);
    percorrer_vetor(v, n);

    //free(v); //pq esse free travou o código? pq esse vetor deveria ser liberado dentro da função, pois foi criado lá e não na main

    printf("======== CRIA SEQUENCIA ========\n");

    int *pv = cria_sequencia(n);
    percorrer_vetor(pv, n);

    //achar_erros();

    free(v);
    free(pv);

    printf("vetores liberados.\n"); //agr consigo chegar aqui eba, antes nao conseguia pq os vetores eram criados dentro das funções, e a main não tinha nada para liberar

    return 0;
}