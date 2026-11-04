#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*1) Usando as funções rand/srand para gerar números aleatórios (#include <stdlib.h> e #include <time.h>), escreva um programa que gere X sequências de N dezenas com valores entre 01 à 99. Não pode haver repetição entre as dezenas sorteadas dentro das sequências (pode usar vetores).

2) permitir que a quantidade de sequências, de dezenas e repetições sejam escolhidas pelo usuário
*/

void gerar_num_aleatorios () {
    const int maxSequencias = 100, maxDezenas = 100;
    int sequencia[maxSequencias][maxDezenas], num;
    int min = 1, max = 99, valido = 1;
    int maxRepeticoes = 0, qteSequencias, qteDezenas;

    printf("============= SORTEIO NUMEROS =================\n");

    //pedir parametros
    printf("quantidade de sequencias [max=%d]: ", maxSequencias);
    scanf(" %d", &qteSequencias);
    printf("quantidade de dezenas [max=%d]: ", maxDezenas);
    scanf(" %d", &qteDezenas);
    printf("repeticoes por sequencia: ");
    scanf(" %d", &maxRepeticoes);

    printf("------------------------------------------------\n");

    if (qteDezenas > maxDezenas || qteSequencias > maxSequencias) {
        valido = 0;
        printf("valores invalidos.");
    }

    if (valido) {//gerar sequencias
        for (int i = 0; i < qteSequencias; i++) {
            int j = 0;
            //gerar dezenas
            while (j < qteDezenas) {
                int qteRepeticoes = 0;
                //gerar num aleatorio
                num = (rand() % (max - min + 1) + min);
                //checar se há repetições
                for (int k = 0; k < j; k++) {
                    if (sequencia[i][j] == num) qteRepeticoes++;
                    if (qteRepeticoes > maxRepeticoes) break;
                }
                //alocar na matriz
                if (qteRepeticoes <= maxRepeticoes) {
                    sequencia[i][j] = num;
                    j++;
                }
            }
        }

        //imprimir
        for (int i = 0; i < qteSequencias; i++) {
        printf("[ ");
            for (int j = 0; j < qteDezenas; j++) {
                if (sequencia[i][j] > 9) printf("%d ", sequencia[i][j]);
                else printf("0%d ", sequencia[i][j]);
            }
        printf("]\n");
        }
    }

}

/*DUVIDAS:
nesse contexto, o que são sequencias, dezenas e repetições?

repetições = qte q um mesmo numero pode aparecer
sequencias = quantas listas
dezenas = qte de elementos em cada lista

o termo dezenas e sequencias foi usado pois remete a cartelas de loterias, fiquei confusa com isso

como fazer isso sem alocação dinamica? (nao da)
*/

int main () {
    srand(time(NULL));
    gerar_num_aleatorios();
    return 0;
}