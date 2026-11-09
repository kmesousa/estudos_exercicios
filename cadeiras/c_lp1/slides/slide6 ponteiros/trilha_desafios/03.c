#include <stdio.h>
#include <stdlib.h>
#include "02.c"

/*Desafio 3.1: Vetor dinâmico
Leia n do teclado, aloque n inteiros com malloc, preencha com os quadrados (1, 4, 9...), imprima e libere. Sempre teste se o malloc retornou NULL.*/

void alocar_vetor(int *v, int n) {
    v = (int *) malloc( n*sizeof(int) ); //como que o v consegue acessar esse vetor fora dessa função? como esse valor nao é sobreescrito dps? já que ele deveria ser local para essa função
}

void preencher_quadrados (int *v, int n) {
    int q = 1;
    for (int i = 0; i < n; i++) {
        *v++ = (q)*(q);
        q++;
    }
}

/*Desafio 3.2: Retornar memória alocada
Escreva int *cria_sequencia(int n) que aloca, preenche com 0..n-1 e retorna o ponteiro. Quem libera? Onde? Escreva a resposta como comentário.*/

void preencher_sequencia (int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i+1;
    }
}

int *cria_sequencia (int n) {
    int *v;
    alocar_vetor(v, n);
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

    alocar_vetor(v, n);
    preencher_quadrados(v, n);
    percorrer_vetor(v, n);

    //free(v); //pq esse free travou o código?

    printf("======== CRIA SEQUENCIA ========\n");

    int *pv = cria_sequencia(n);
    percorrer_vetor(pv, n);

    achar_erros();

    free(v);
    free(pv);

    printf("vetores liberados.\n"); //pq eu nao consigo chegar aqui?

    return 0;
}