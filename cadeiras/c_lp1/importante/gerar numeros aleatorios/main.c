#include <stdio.h>
#include <stdlib.h> // 1. Necessária para usar rand() e srand()
#include <time.h>   // 2. Necessária para usar time()

void vetor_aleatorio() {
    const int n = 60;
    int vetor[n];
    const int max = 100, min = 0;

    // 3. Alimenta a fórmula com o segundo atual (só roda UMA vez)
    srand(time(NULL));

    // 4. Preenche o vetor posição por posição
    for (int i = 0; i < n; i++) {
        // Gera um número gigante e pega o resto por 100 (valores de 0 a 99)
        vetor[i] = (rand() % (max - min + 1) + min);

        // Imprime o número na tela para você ver
        printf("%d ", vetor[i]);
    }
    printf("\n"); // Pula uma linha no final
}

int main () {
    vetor_aleatorio();
    return 0;
}