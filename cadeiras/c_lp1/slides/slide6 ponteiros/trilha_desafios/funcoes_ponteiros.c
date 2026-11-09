#include <stdio.h>

void percorrer_vetor (int *ptVetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("indice %d valor %d\n", i, *(ptVetor++));
    }
}

void info_ponteiro (int *p, int expandido) {

    if (expandido) printf("endereco do ponteiro  &p   = %d\n", &p);
    printf("conteudo do ponteiro  p    = %d\n", p);
    if (expandido) printf("endereco do conteudo  &*p  = %d\n", &*p);
    printf("valor do conteudo     *p   = %d\n\n", *p);

}