#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

/*Para multiplicar duas matrizes (\(A \cdot B\)), a única exigência é que o número de colunas da primeira matriz (\(A\)) seja igual ao número de linhas da segunda matriz (\(B\)).
• Se a matriz \(A\) tem tamanho \(m \times \mathbf{n}\)
• E a matriz \(B\) tem tamanho \(\mathbf{n} \times p\)

A = [1, 2, 3], [4, 5, 6], [7, 8, 9] m X n = 2 X 3 aij

B = [1, 2 2343 24], [3, 4 244 24], [5, 6 24 23] n X p = 3 X 2 bjk

C = m X p ik

*/
void multiplicar_matrizes (int matriz1[MAX][MAX], int matriz2[MAX][MAX], int m, int n, int p) {
    
}

void matriz_0_1 () {
    const int TAM = 1024;
    int matriz[TAM][TAM];
    int seq_atual = 0, maior_seq_lin = 0, maior_seq_col = 0;
    int lin, col;
    int eh_seq = 0;

    //preencher com valore aleatorios e checar seqs nas linhas
    for (int i = 0; i<TAM; i++) {

        //resetar sequencia ao quebrar linha
        seq_atual = 0;
        eh_seq = 0;

        //imprimir
        printf("[ ");

        for (int j = 0; j<TAM; j++) {
            int num = (rand() % 2);
            matriz[i][j] = num;

            //formar seq
            if (num) {
                if (eh_seq) seq_atual++;
                eh_seq = 1;
            }
            else eh_seq = 0;

            //checar maior
            if (seq_atual > maior_seq_lin) maior_seq_lin = seq_atual; lin = i;

            //imprimir matriz
            printf("%d ", num);
        }

        printf("]\n");
        
    }

    //checar sequencias das colunas
    for (int j = 0; j < TAM; j++) {

        //mudança de coluna quebra a sequencia
        eh_seq = 0;
        seq_atual = 0;
    
        for (int i = 0; i < TAM; i++) {            
            int num = matriz[i][j];

            //controle sequencia
            if (num) {
                if (eh_seq) seq_atual++;
                eh_seq = 1;
            }
            else eh_seq = 0;

            //checar maior
            if (seq_atual > maior_seq_col) maior_seq_col = seq_atual; col = j;

        }
    }

    //definir maior seq entre linhas e colunas
    printf("a maior seq de 1s nas linhas tem tamanho %d e esta na linha %d\n", maior_seq_lin, lin);
    printf("a maior seq de 1s nas colunas tem tamanho %d e esta na coluna %d\n", maior_seq_col, col);

    if (maior_seq_lin==maior_seq_col) {

    }
    else if (maior_seq_lin > maior_seq_col) {

    }
    else {
        
    }

}


int questoes_2025_2 () {
    srand(time(NULL));
    matriz_0_1();
    return 0;
}