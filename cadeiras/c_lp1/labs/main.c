#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bucarString.cpp" //ah entao nao era tao dificil assim, AAAAA
#include "lerString.cpp"

#define MAX 99999
#define MIN 10000

/*gerar numero aleatorio*/
int gerarNumero (int max, int min) {
    return rand() % (max - min) + min;
}

/*2) Crie uma agenda em C para armazenar telefones de n pessoas (n entrado pelo usuário).
Crie uma função void addTelefone(int *agenda, int numero, int* contador); que adiciona um número ao 1º espaço em branco da agenda
a. dica: utilize um contador passado por referência, para guardar o nº de registros*/
void addTelefone (int *agenda, int numero, int* contador) { //qual a diferença entre int *var e int*var ?
    //adiciona um numero ao primeiro espaço em branco da agenda, mas como dizer qual o primeiro espaço em branco da agenda?

    int *temp = realloc(agenda, sizeof(int)*(*contador + 1));
    agenda = temp;
    *contador = *contador + 1; //aqui ta acessando a variavel para qual o ponteiro aponta
    //pq *contador++ não funciona, não deveria ser a mesma coisa?
    //contador++ iria incrementar o contador

    agenda[*contador - 1] = gerarNumero(MAX, MIN);
}

/*remove o ultimo numero da agenda*/
void delUltimoTelefone (int *agenda, int* contador) {

}

/*remover o numero de telefone de um indice dado, checar se o indice é um numero primeiro*/
void delTelefone (int *agenda, int indice, int* contador) {


}

void preencherAgenda (int *agenda, int numero) {
    for (int i = 0; i < numero; i++) {
        agenda[i] = gerarNumero(MAX, MIN);
    }
}

void imprimirAgenda (int *agenda, int numero) {
    printf("=== AGENDA COM %d REGISTROS ===\n", numero);
    for (int i = 0; i < numero; i++) {
        printf("%d\n", agenda[i]);
    }
}

int main(void) {
    lerString_Main();

    printf("Hello, World!\n");
    srand(time(NULL));

    int numRegistros;
    int *contador = &numRegistros;
    int resposta = 1;

    printf("Numero de registros: ");
    scanf(" %d", &numRegistros);

    // v = malloc(tam0 * sizeof(int));

    int *agenda = (int *) malloc(sizeof(int) * numRegistros);
    preencherAgenda(agenda, numRegistros);

    imprimirAgenda(agenda, numRegistros);

    while (resposta) {
        printf(("[1] para adicionar numero ao registro.\n[0] sair\n"));
        printf((">> "));
        scanf(" %d", &resposta);

        if(resposta == 1) {
            addTelefone(agenda, numRegistros, contador);
            imprimirAgenda(agenda, numRegistros);
        }
    }

    printf("fim do programa.\n");

    return 0;
}
