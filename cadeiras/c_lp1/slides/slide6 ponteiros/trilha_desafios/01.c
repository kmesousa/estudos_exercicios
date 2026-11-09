#include <stdio.h>
#include <stdlib.h>

/*
& "C:\Users\Caua\all kme\03. tech\estudos_exercicios\cadeiras\c_lp1\slides\slide6 ponteiros\trilha_desafios.exe"
//rodar
*/

/*desafios PARTE 1

Desafio 1.1: Troca
Escreva void troca(int *a, int *b) e teste no main com duas variáveis. Antes de rodar, escreva em um comentário o que você espera ver.

Desafio 1.2: Endereços
Declare int x = 10; int *p = &x; int **pp = &p;. Imprima x, &x, p, *p, &p, pp, *pp, **pp. Depois, sem rodar, diga qual valor é igual a qual. Em seguida altere x usando só pp.

Desafio 1.3: Min e max por ponteiro
Escreva void min_max(int *v, int n, int *min, int *max). A função devolve dois resultados pelos parâmetros. (É o mesmo mecanismo que o solver vai usar para devolver linha e coluna do E em find_position.)

*/

void info_ponteiro (int *p, int expandido) {

    if (expandido) printf("endereco do ponteiro  &p   = %d\n", &p);
    printf("conteudo do ponteiro  p    = %d\n", p);
    if (expandido) printf("endereco do conteudo  &*p  = %d\n", &*p);
    printf("valor do conteudo     *p   = %d\n\n", *p);

}

void colinha_ponteiros () {

    int var = 67; //variavel int normal
    int *pont = &var; //ponteiro apontando para o edenreço de memmoria de var
    int **pont2 = &pont; //ponteiro2 apontando para o endereço de memoria do ponteiro 1

    printf("========= COLINHA PONTEIROS ===========\n");
    printf("endereco &var  %d conteudo var %d\n", &var, var);
    printf("&pont %d  pont %d &*pont %d *pont %d\n", &pont, pont, &*pont, *pont);
    printf("&pont2 %d pont2 %d &*pont2 %d *pont2 %d &**pont2 %d **pont2 %d\n", &pont2, pont2, &*pont2, *pont2, &**pont2, **pont2);

    printf("&pont eh o endereco do ponteiro \npont = &*pont eh o endereco do conteudo armazenado no ponteiro \n*pont eh o conteudo armazenado\n");

    printf("----------- DECLARACAO DE PONTEIROS! -------------------\n");

    printf("na declaracao int *p = &var\n");
    int a = 19;
    int *p = &a;

    info_ponteiro(p, 1);

    printf("dps da declaracao p = &var\n");
    int b = 21;
    p = &b;

    info_ponteiro(p, 1);

    printf("se fizer *p = var, vai trocar o valor da variavel para qual o ponteiro aponta\n");

    *p = a;
    info_ponteiro(p, 1);

}

void colinha_array_matriz () {

    printf("======== ARRAYS E MATRIZES COM PONTEIROS =====\n");

}

void troca (int *pa, int *pb) {

    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    //ta mudando diretamente os conteudos de a e b
    //como fazer para mudar os enderecos q pa e pb apontam? seria outra coisa e print(a, b) continuaria retornando os valores originais

    /*analise
    fazer pb = 30 (ou pb = var), por exemplo, nao daria certo, pois esta tentando colocar um valor inteiro em um ponteiro
    em contrapartida, fazer *pb = 30 (ou *pb =var) daria certo, pois esta dizendo o conteudo do ponteiro vai ser o valor passado
    *pb = &var tbm daria certo, mas seria uma coisa diferente, estaria mudando o endereco do ponteiro para o de outra variavel, o primeiro muda o valor da variavel a qual o ponteiro ja esta apontando
    */

    /*nessa funcao

    int *temp = pb; \\ um ponteiro temp recebe como conteúdo o endereco do conteúdo de pb

    *pa = *pb; \\ o valor do conteúdo de pb recebe o valor do conteúdo de pb

    *pb = *temp; \\ o valor do conteúdo de pb recebe o valor do conteúdo de temp

    */

    /*duvidas

    pq nao poderia fazer

    *pa = pb?

    pensei q isso estaria simulando a declaração de ponteiros, mas está errado, na delcaração *pa = &var

    como pb é o endereço do valor armazenado, poderia estar certo, mas não esta, pois *pa nao recebe o endereço, mas sim o valor

    poderia entao fazer pa = pb ? creio que sim, mas não é isso que a função deve fazer, ela deve trocar os valores das variaveis a e b, não trocar o que pa e pb apontam
    */

    //pb = 30; //da erro, mais pq?? ah faz sentido, to tentando colocar um valor inteiro em um ponteiro, mas ele deveria receber um local de memoria

    //*pb = 30; // da certo? sim
}

void troca_errada (int *pa, int *pb) { //nao é esse o objetivo da função!
    int * temp = pb;

    pa = pb; //pa vai apontar para o que pb endereço aponta
    pb = temp; //nao daria certo, pois temp nao existe fora da funcao;
}

void alter_var_com_pp (int **pp, int novo) {

    **pp = novo; //eh tao simples n sei nem pq eu me preocupei por um segundo
    /* **pp é o valor do conteudo do ponteiro *p que **p aponta, pode ser alterado diretamente */

}

void imprimir_vetor_com_ponteiros(int *v, int n, int detalhe) {

    for (int i = 0; i<n; i++) {
        if (detalhe) printf("indice %d endereco %d valor %d\n", i, (v+i), *(v+i));
        else printf("%d ", *(v+i));
    }
}

void min_max(int *v, int n, int *min, int *max) { //v = ponteiro apontando para primeiro elemento de um vetor, n = numero de elementos do vetor, min = ponteiro que vai apontar pro menor elemento, max = ponteiro que vai apontar pro maior elemento

    //min e max recebem o endereço do primeiro valor do vetor
    *min = v[0];
    *max = v[0];

    info_ponteiro(min,0);
    info_ponteiro(max,0);
    info_ponteiro(v,0);

    //percorrendo o vetor
    for (int i = 1; i < n; i++) {
        //*(v+i) = v[i]
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
        // info_ponteiro(v+i, 0);
        // printf("info min \n");
        // info_ponteiro(min,0);
        // printf("info max \n");
        // info_ponteiro(max,0);
    }

    printf("dentro da funcao: \n");
    printf("o valor min eh %d\n", *min);
    printf("o valor max eh %d\n", *max);

    // info_ponteiro(min, 0);
    // info_ponteiro(max, 0);
}

int main () {

    colinha_ponteiros();

    printf("------------- TROCA SIMPLES ----------\n");

    int a = 20;
    int b = 10;

    int *pa = &a;
    int *pb = &b;

    printf("original\n");
    printf("pa %d pb %d\n", *pa, *pb);
    printf("a eh' %d e b eh' %d\n", a, b);

    troca(pa, pb);
    printf("troca 1\n");
    printf("pa %d pb %d\n", *pa, *pb);
    printf("a eh' %d e b eh' %d\n", a, b);

    troca(&a, &b); //tbm da certo
    printf("troca 2\n");
    printf("pa %d pb %d\n", *pa, *pb);
    printf("a eh' %d e b eh' %d\n", a, b);

    printf("------------- ALTERAR VAR PELO PONTEIRO DUPLO **PP ----------\n");

    int c = 67;
    int *p = &c;
    int **pp = &p;

    printf("var c eh %d\n", c);
    alter_var_com_pp(pp, 21);
    printf("var c eh %d\n", c);

    printf("----------- ANALISE VETOR COM PONTEIROS -------------------\n");
    int *v;
    int n;
    int vetor[] = {10, 67, 21, 19};

    n = sizeof(vetor)/sizeof(vetor[0]);

    v = vetor;
    //v = &vetor[0]; //mesma coisa que o de cima

    printf("  analise de ponteiro e vetores\n");
    printf("n = %d\n", n);
    printf("%d %d %d\n", v, vetor, &vetor[0]);
    printf("%d %d %d\n", *v, *vetor, *&vetor[0]);

    printf("valor + 1 %d endereco + 1 = prox valor %d\n", *v+1, *(v+1));

    int i = 0;
    printf("indice i %d endereco %d valor %d\n", i, (v+i), *(v+i));

    printf("       percorrer vetor com ponteiro      \n");

    imprimir_vetor_com_ponteiros(v, n, 1);

    printf("----------- MIN MAX COM PONTEIROS -------------------\n");
    int max, min;
    min_max(v, n, &min, &max);

    printf("fora da funcao: \n");

    // info_ponteiro(min, 0);
    // info_ponteiro(max, 0);

    printf("o valor min eh %d\n", min);
    printf("o valor max eh %d\n", max);

    return 0;
}

/*
& "C:\Users\Caua\all kme\03. tech\estudos_exercicios\cadeiras\c_lp1\slides\slide6 ponteiros\trilha_desafios.exe"
//rodar
*/