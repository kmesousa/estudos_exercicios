#include <stdio.h>

/*Desafio 2.1: Percorrer sem colchetes
Imprima um vetor de 5 inteiros usando só aritmética de ponteiros (*(p + i) e depois p++), sem v[i]. Depois descubra o que sizeof(v) e sizeof(p) imprimem e por quê são diferentes.*/

void percorrer_vetor (int *ptVetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("indice %d valor %d\n", i, *(ptVetor++));
    }
}

/*Desafio 2.2: Inverter no lugar
Escreva void inverte(int *v, int n) usando dois ponteiros, um começando no início e outro no fim, que se encontram no meio.*/

void inverter(int *v, int n) {
    int *fim = v + n - 1;

    while (v < fim) {
        int temp = *v;
        *v = *fim;
        *fim = temp;
        v++;
        fim--;
    }
}

/*Desafio 2.3: Strings
Escreva int tamanho(char *s) (seu próprio strlen) e void copia(char *dest, char *src) (seu próprio strcpy), só com ponteiros.*/

int tamanho_string (char *s) {
    int tam = 0;
    while (*(s) != '\0') {
        tam++;
        s++;
    }
    //while (*s++) tam++;
    return tam;
}

void copia_string(char *dest, char *src) { //meta: fazer com malloc dps
    while (*(src) != '\0') {
        *dest++ = *src++;
    }

    *dest = '\0';
}

int main_2() {

    printf("======== ENTENDO PONTEIRO ==========\n");

    int vetor[] = {1, 2, 3, 4, 5};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int *ptr = vetor;

    printf("size of vetor %d\n", sizeof(vetor));
    printf("size of ponteiro %d\n", sizeof(ptr));

    printf("%d %d\n", ptr, *ptr);

    printf("======== PERCORRER PONTEIRO ==========\n");

    percorrer_vetor(vetor, n);
    percorrer_vetor(&vetor[0], n);

    printf("======== INVERTENDO VETOR ==========\n");

    inverter(vetor, n);
    percorrer_vetor(vetor, n);

    printf("======== STRLEN ==========\n");

    char string[] = "griddlehark supremacy\0";

    printf("%s\n", string);
    printf("o tamanho da string eh %d \n", tamanho_string(string));
    //percorrer_vetor(string, tamanho(string)); //nao da certo pq percorrer vetor é para int

    printf("======== STRCOPY ==========\n");

    char nova_string[50];

    copia_string(nova_string, string);
    printf("%s", nova_string);

    return 0;
}