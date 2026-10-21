/*Lab 1: "Spawning de Entidades" – Usar malloc para alocar espaço para N partículas de uma explosão no momento da ação, seguido de free.
Lab 2: "Buffer Dinâmico" – Ler a resolução desejada pelo usuário, alocar dinamicamente o total de pixels da matriz, preencher com um valor base e liberar o buffer.

*/
#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int n) {
    int *tmp;
    //alocar
    tmp = (int * ) malloc (n * sizeof(int));
    if (tmp == NULL) return NULL;

    return tmp;
}

void alocarMatriz(int linhas, int colunas, int ***matriz){
    //*** >>> ** >> *
    int **tmp;

    tmp = (int ** )malloc( linhas * (sizeof(int *))); //linhas do tamanho de ponteiros de vetores
    for (int i = 0; i < colunas; i++) {
        tmp[i] = alocarVetor(colunas);
    }

    *matriz = tmp;
    //matriz = tmp; //nao da certo, pois são tipos de dados diferentes

    return;
}

int main () {
    // int * vetor;
    // int n;

    // printf(">> ");
    // scanf(" %d", &n);
    // vetor = alocarVetor(n);
    // for (int i = 0; i < n; i++) vetor[i] = i+1;
    // for (int i = 0; i < n; i++) printf("%d ", vetor[i]);
    // free(vetor);
    // printf("deu certo!");

    int **matriz;
    int linhas, colunas;

    printf("linhas: ");
    scanf("%d", &linhas);
    printf("colunas: ");
    scanf("%d", &colunas);

    alocarMatriz(linhas, colunas, &matriz);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) matriz[i][j] = i*j;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }
    //free(matriz);
    return 0;
}