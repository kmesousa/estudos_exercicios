#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int* prtA, int* prtB) {
    int temp = *prtA;
    *prtA = *prtB;
    *prtB = temp;
}

//imprimir array
void imprimir_array (int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void imprimir_array2 (int* arr, int size) { //com aratimetica de ponteiros
    for (int i = 0; i < size; i++) printf("%d ", *arr++);
    printf("\n");
}

//inverter array
void inverter_array (int* arr, int size) {
    for (int i = 0; i < size/2; i++) {
        troca(arr + i, arr + size - i - 1); //é o mesmo que:
        // int temp = *(arr + i);
        // *(arr + i) = *(arr + size - i - 1);
        // *(arr + size - i - 1) = temp;
    }
}

int remove_k (int arr[], int size, int k) {
    int new_size;

    return new_size;

}

int main () {
    //troca declarando ponteiros na main para passar na função
    int *ptrA, *ptrB;
    int a = 10, b = 20;
    ptrA = &a;
    ptrB = &b;
    troca(ptrA, ptrB);
    printf("a e' %d e b e' %d\n", a, b);

    //troca passando diretamente os endereços na função
    a = 10, b = 20;
    troca(&a, &b);
    printf("a e' %d e b e' %d\n\n", a, b); //TAMBÉM DA CERTO EBA

    //outros testes
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptrC = &v[0];
    printf("%d, %d\n", ptrC, *ptrC);
    ptrC += 2;
    printf("%d, %d\n", ptrC, *ptrC); //uau, incrível
    *ptrC = 0;
    printf("%d, %d\n", ptrC, *ptrC);
    for (int i = 0; i < 10; i++) printf("%d ", v[i]);
    printf("\n\n");

    //teste
    a = 30, b = 5;
    int *p = &a, *q = &b;
    printf("%d - %d = %d\n", p, q, p - q);
    printf("%d - %d = %d\n", *p, *q, *p - *q);

    //ponteiro de ponteiros
    int var = 67;
    int *pont= &var, **pont2 = &pont;

    printf("\nendereco var %d valor var %d\n", &var, var);
    printf("%d %d %d %d\n", &pont, pont, &*pont, *pont);
    printf("%d %d %d %d %d %d\n", &pont2, pont2, &*pont2, *pont2, &**pont2, **pont2);
    //q interessante

    //imprimir array
    int v2[] = {1, 2, 3, 4, 5};
    int n = sizeof(v2) / sizeof(v2[0]); //pq isso nao ta retornando o tamanho certo??
    printf("%d\n", n);

    imprimir_array(v2, n);

    //imprimir array com aritimetica de ponteiros
    int *pArr = v2;
    imprimir_array2(pArr, n);
    imprimir_array2(v2, n);
    imprimir_array2(&v2[0], n);
    //imprimir_array2(&v2, n); //daria erro

    //exercicio 1: INVERTER ARRAY
    inverter_array(v2, n);
    imprimir_array2(v2, n);

    //exercicio 2:


    //exercicio 3:

    return 0;
}