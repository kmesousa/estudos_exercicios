#include <stdio.h>
#include <stdlib.h>
#include "funcoes_ponteiros.c"

/*Nível 4: calloc e realloc

Desafio 4.1: malloc vs calloc
Aloque 5 inteiros com malloc e imprima sem inicializar. Faça o mesmo com calloc. Explique a diferença com suas palavras e reescreva o calloc usando malloc + um loop (ou memset).
*/

int* alocar_malloc ( int n) {
    int *v = malloc (n * sizeof(int));
}

int* alocar_calloc ( int n) {
    int *v = calloc(n, n* sizeof(int));
}

//NAO TESTEI SE ISSO DA CERTO AINDA!
void alocar_com_tentativas (int **v, int n, int tentativas) {
    for (int t = 0; t < tentativas && v == NULL; t++) {
        v = alocar_malloc(n);
    }
}

/*Desafio 4.2: Vetor que cresce
Leia números do teclado até digitar -1, sem saber quantos serão. Comece com capacidade 2 e dobre com realloc quando encher. No final, imprima os números e libere.
Dica de armadilha: não faça v = realloc(v, ...) direto. Se falhar, você perde o ponteiro original. Use um ponteiro temporário e teste.

Desafio 4.3: Remover do meio
Com o vetor do 4.2, faça remove_ultimo(...). Isso é exatamente o que remove_movement vai fazer no backtracking. Depois faça uma versão que encolhe com realloc quando o uso cai abaixo de 1/4 da capacidade.*/

int main () {


    printf("====  MALLOC VS CALLOC ====\n");
    int *m, *c;
    int n = 5;

    m = alocar_malloc(n);
    c = alocar_calloc(n);

    printf("malloc\n");
    percorrer_vetor(m, n);

    printf("calloc\n");
    percorrer_vetor(c, n);

    free(m); m = NULL;
    free(c); c = NULL;

    printf("\nvetores liberados.\n\n");

    printf("===== VETOR DINAMICO ======\n");

    const int TAM_INCIAL = 2;
    int tam = TAM_INCIAL;

    int v[TAM_INCIAL];
    int valor = 1;
    int i = 0;

    printf("insira valores para o vetor\n");
    while (valor != -1) {
        printf("[%d] ", i++);
        scanf(" %d", valor);
    }

    printf("o vetor final eh\n");


    return 0;
}