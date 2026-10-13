/* Lab 2: "Layout de Relatório" – Ler três valores decimais representando o tempo de resposta de um servidor e imprimi-los em uma tabela perfeitamente alinhada usando especificadores (ex: %8.2f). */

#include <stdio.h>

void relatorio (void) {
    printf("=== RELATÓRIO ===\n");

    //coleta de dados
    float t1, t2, t3;

    printf("tempo 1: ");
    scanf("%d", &t1);
    printf("tempo 2: ");
    scanf("%d", &t2);
    printf("tempo 3: ");
    scanf("%d", &t3);

    //impressao da tabela

}

int main() {
    relatorio();
    return 0;
}