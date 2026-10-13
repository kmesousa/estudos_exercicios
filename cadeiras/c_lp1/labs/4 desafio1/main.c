#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
4) Faça um programa para interpretar operações em conjuntos de números inteiros. As operações que devem ser implementadas são interseção e união. O usuário deve informar a expressão como um comando no terminal, sendo que ele usará a letra u para união e a letra i para intersecção. O programa deve ter suporte para 3 vetores (A, B, e C) de 5 valores cada. Exemplos de expressão:
AuB
AiC
AuBiC
AiAuB

*os conjuntos internamente podem ter elementos repetidos. Os resultados das operações não podem ter repetiçõesp
*/

//opicional
//gerar conjuntos aleatoriamente (iria remover repetições desde já ou não?)
//mostrar resultados intermediários das operações

void operar_conjuntos () {
    //const int tamConjuntos = 5, qteConjuntos = 3;
    //char nomeConjuntos[qteConjuntos] = {'A', 'B', 'C'};
    //resultado[tamConjuntos * qteConjuntos] queria poder fazer isso :(
    //int conjuntos[qteConjuntos][tamConjuntos] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7}; //exemplo de conjuntos
    char expressao[20];
    char nomeConjuntos[] = {'A', 'B', 'C'};
    int conjuntos[][5] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7};
    int tamConjuntos = 5, qteConjuntos = sizeof(nomeConjuntos) / sizeof(nomeConjuntos[0]);

    //criar conjuntos aleatórios usando rand()

    //imprimir conjuntoos e operações validas
    printf("================ EXPRESSOES COM CONJUNTOS INTEIROS ===============\n");
    printf("Conjuntos validos: \n");
    for (int i = 0; i < qteConjuntos; i++) {
        printf("[%c] = {", nomeConjuntos[i]);
        for (int j = 0; j < tamConjuntos; j++) {
            printf("%d ", conjuntos[i][j]);
        }
        printf("}\n");
    }
    printf("Operadores validos: \n[i] interesccao \n[u] uniao\n");

    //pedir entrada da expressao a ser realizada
    printf("Digite a expressao de conjuntos\n>> ");
    scanf(" %19[^\n]", expressao);


    int resultado[15], tamResultado = 0; //tamanho máximo do resultado é 15 (5 elementos de cada conjunto)
    int tempResultado[15], tempTam = 0; //variaveis auxiliadoras para resultados temporários

    int i = 0, valido = 0;
    int lhs = -1, rhs;
    char operador;

    while (expressao[i] != '\0') {

        if (expressao[i]==' ') { //ignorar espaços em branco
            i++;
            continue;
        }

        if (lhs==-1) { //primeiro elemento a ser achado deve ser um conjunto, obrigatoriamente
            for (int j = 0; j<qteConjuntos; j++) {
                if (expressao[i] == nomeConjuntos[j]) {
                    lhs = j; //indice do conjunto (indice nome conjunto = indice conjunto)
                    valido = 1;
                    break;
                }
            }
            if (!valido) break; //cancelar se não encontrar conjunto válido

            //armazenar no resultado intermediário para economizar código (nao precisar 2 opçoes de u e i)
            for (int j = 0; j < tamConjuntos; j++) { //percorrer conjunto
                int repetido = 0;
                for (int k = 0; k < tamResultado; k++) //percorrer vetor resultado atual
                    if (conjuntos[lhs][j] == resultado[k]) { //se já tiver no vetor resultado, nao irá adicionar
                        repetido = 1;
                        break;
                    }
                if (!repetido) resultado[tamResultado++] = conjuntos[lhs][j]; //se nao tiver repetido, adicionar no prox indice do vetor resultado
            }
        }

        else if (expressao[i]=='i' || expressao[i]=='u') { //só entra aqui se já tiver lhs
            operador = expressao[i];
            i++;

            while (expressao[i]==' ') i++; //ignorar espaços em branco

            valido = 0;
            for (int j = 0; j<qteConjuntos; j++) { //encontrar conjunto a direita
                if (expressao[i] == nomeConjuntos[j]) {
                    rhs = j; //salvar indice do conjunto
                    valido = 1;
                }
            }
            if (!valido) break;

            tempTam = 0;

            switch (operador)
            {
                case 'u':{ //realizar operacao de uniao
                    for (int j = 0; j < tamResultado; j++) { //colocar resultado no temporario (oper anteior ou primeiro lhs)
                            tempResultado[tempTam++] = resultado[j];
                    }
                    for (int j = 0; j < tamConjuntos; j++) { //percorrer o conjunto rhs
                        int repetido = 0;
                        for (int k = 0; k < tempTam; k++) //percorrer o resultado temporario
                            if (conjuntos[rhs][j] == tempResultado[k]) {
                                repetido = 1; //checar se elemento do rhs já está no conjunto resultado
                                break;
                            }
                        if (!repetido) { //adicionar apenas se for inétido
                            tempResultado[tempTam++] = conjuntos[rhs][j];
                        }
                    }
                    break;
                }
                case 'i':{ //realizar operacao de intersecao
                    for (int j = 0; j < tamResultado; j++) { //percorrer vetor resultado
                            for (int k = 0; k < tamConjuntos; k++) { //percorrer conjunto rhs
                                if (resultado[j] == conjuntos[rhs][k]) { //adicionar somente se pertencer a ambos
                                    tempResultado[tempTam++] = resultado[j];
                                    break;
                                }
                            }
                    }
                    break;
                }
            }

            //atualizar resultado com o que foi calculado
            for (int j = 0; j < tempTam; j++) {
                resultado[j] = tempResultado[j];
            }
            tamResultado = tempTam;
        }

        else { //se nao for espaço, conjunto ou operador já tendo um conjunto, declara inválido
            valido = 0;
            break;
        }

        //mostrar resultados intermediários das operações?

        i++;

    }

    //imprimir resultado
    if (!valido) {
        printf("invalido");
    }
    else {
        printf("Resultado: { ");
        for (int j = 0; j < tamResultado; j++) printf("%d ", resultado[j]);
        printf("}\n");
    }
}

int main () {
    srand(time(NULL)); //se fosse gerar conjuntos aleatoriamente
    operar_conjuntos();
    return 0;
}