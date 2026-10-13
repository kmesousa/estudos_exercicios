#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void operar_conjuntos() {
    char expressao[20];
    char nomeConjuntos[] = {'A', 'B', 'C'};
    int conjuntos[][5] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7};
    int tamConjuntos = 5;
    int qteConjuntos = sizeof(nomeConjuntos) / sizeof(nomeConjuntos[0]);

    printf("Digite a expressao de conjuntos (ex: AuB, AiC, AuBiC, AiAuB): ");
    scanf(" %19[^\n]", expressao);

    int resultado[15], tamResultado = 0;
    int tempResultado[15], tempTam = 0;

    int i = 0, valido = 1;
    int lhs = -1, rhs;
    char operador;

    while (expressao[i] != '\0') {

        if (expressao[i] == ' ') { i++; continue; }

        if (lhs == -1) {
            int achou = 0;
            for (int j = 0; j < qteConjuntos; j++) {
                if (expressao[i] == nomeConjuntos[j]) { lhs = j; achou = 1; break; }
            }
            if (!achou) { valido = 0; break; }
        }

        else if (expressao[i] == 'i' || expressao[i] == 'u') {
            operador = expressao[i];
            i++;
            while (expressao[i] == ' ') i++;

            valido = 0;
            for (int j = 0; j < qteConjuntos; j++) {
                if (expressao[i] == nomeConjuntos[j]) { rhs = j; valido = 1; break; }
            }
            if (!valido) break;

            tempTam = 0;

            if (lhs > qteConjuntos) {
                // lhs é o resultado acumulado até agora
                switch (operador) {
                case 'u':
                    for (int j = 0; j < tamResultado; j++)
                        tempResultado[tempTam++] = resultado[j];
                    for (int j = 0; j < tamConjuntos; j++) {
                        int repetido = 0;
                        for (int k = 0; k < tempTam; k++)
                            if (conjuntos[rhs][j] == tempResultado[k]) { repetido = 1; break; }
                        if (!repetido) tempResultado[tempTam++] = conjuntos[rhs][j];
                    }
                    break;
                case 'i':
                    for (int j = 0; j < tamResultado; j++)
                        for (int k = 0; k < tamConjuntos; k++)
                            if (resultado[j] == conjuntos[rhs][k]) { tempResultado[tempTam++] = resultado[j]; break; }
                    break;
                }
            }
            else {
                // primeira operação: lhs e rhs ainda são A, B ou C
                switch (operador) {
                case 'u':
                    for (int j = 0; j < tamConjuntos; j++) {
                        int repetido = 0;
                        for (int k = 0; k < tempTam; k++)
                            if (conjuntos[lhs][j] == tempResultado[k]) { repetido = 1; break; }
                        if (!repetido) tempResultado[tempTam++] = conjuntos[lhs][j];
                    }
                    for (int j = 0; j < tamConjuntos; j++) {
                        int repetido = 0;
                        for (int k = 0; k < tempTam; k++)
                            if (conjuntos[rhs][j] == tempResultado[k]) { repetido = 1; break; }
                        if (!repetido) tempResultado[tempTam++] = conjuntos[rhs][j];
                    }
                    break;
                case 'i':
                    for (int j = 0; j < tamConjuntos; j++) {
                        int achouIgual = 0;
                        for (int k = 0; k < tamConjuntos; k++)
                            if (conjuntos[lhs][j] == conjuntos[rhs][k]) { achouIgual = 1; break; }
                        if (achouIgual) {
                            int repetido = 0;
                            for (int k = 0; k < tempTam; k++)
                                if (conjuntos[lhs][j] == tempResultado[k]) { repetido = 1; break; }
                            if (!repetido) tempResultado[tempTam++] = conjuntos[lhs][j];
                        }
                    }
                    break;
                }
                lhs = qteConjuntos + 1;
            }

            for (int j = 0; j < tempTam; j++) resultado[j] = tempResultado[j];
            tamResultado = tempTam;
        }

        else { valido = 0; break; }

        i++;
    }

    if (!valido) {
        printf("invalido");
    } else {
        printf("Resultado: { ");
        for (int j = 0; j < tamResultado; j++) printf("%d ", resultado[j]);
        printf("}\n");
    }
}

int main () {
    srand(time(NULL));
    operar_conjuntos();
    return 0;
}