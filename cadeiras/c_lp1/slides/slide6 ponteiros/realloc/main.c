#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear_num (int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int main () {
    srand(time(NULL));

    //criar vetor dinamicamente

    int *v, tam0;
    int min = 0, max = 10;

    printf("tamanho vetor inicial: ");
    scanf(" %d", &tam0);

    v = malloc(tam0 * sizeof(int));

    if (v == NULL) {
        printf("Falha na alocação\n");
        return 1;
    }

    for (int i = 0; i < tam0; i ++) {
        v[i] = sortear_num(min, max);
    }

    for (int i = 0; i < tam0; i++) {
        printf("%d ", v[i]);
    }

    //aumentar tamanho
    int tam1;

    printf("\ntamanho a adicionar: ");
    scanf(" %d", &tam1);

    int tamFinal = tam1 + tam0;

    //v = realloc(v, (tamFinal)*sizeof(int));
    int *temp = realloc(v, tamFinal * sizeof(int));

    if (temp == NULL) {
        printf("Falha no realloc\n");
        free(v);
        return 1;
    }

    v = temp;

    for (int i = tam0; i < tamFinal; i ++) {
        v[i] = sortear_num(min, max);
    }

    for (int i = 0; i < tamFinal; i++) {
        printf("%d ", v[i]);
    }

    free(v);

    return 0;
}