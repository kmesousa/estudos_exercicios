#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


/*Lab 4: "Bot de Navegação Autônoma e Máquina de Estados" – Implementar um controle de movimentação para um robô explorador utilizando a estrutura seletiva switch/case. O algoritmo deve ler caracteres de comando digitados pelo usuário ('W', 'A', 'S', 'D' ou variações em minúsculo), acionar os atuadores correspondentes para alterar a orientação/posição e incluir a cláusula default para tratar comandos desconhecidos ou paradas de emergência.*/

void navegar() {

    /*problemas e alterações pendentes:
    - fazer com que exiba a lista completa dos movimentos executados, caso a entrada contenha mais de um
    - mostrar os movimentos executados dps q o tabuleiro já tenha sido atualizado para contabiliza-los
    - entender pq esse erro "too many arguments in function call" no print
    */

    //tabuleiro
    int larguraM=20, alturaM = 20;
    //const char bloco = '-';

    //player
    int x = larguraM/2, y = alturaM/2;

    //controle de orientacao do player
    char anterior = 'N';
    char orientacao = 'N';

    //controle e ações
    int continuar = 1;
    char entrada;
    int inicio = 1;
    char resposta;
    int bateu;

    while (continuar) {
        //limpar tela
        bateu = 0;
        limparTela();

        //titulo
        printf("=============== BOT DE NAVEGACAO =================\n");

        //imprimir tabuleiro atual
        for (int i=alturaM; i >= 0; i--) { //linhas / eixo y, diminui de cima pra baixo
            for (int j=0; j <= larguraM; j++) { //colunas / eixo x, aumenta da esquerda para direi
                if (i==y && j==x) {
                    //esc,lher qual a orientacao do player para definir "sprite", com switch e variavel orientação
                    switch (orientacao)
                    {
                        case 'W': {
                            printf("^");
                            break;
                        }
                        case 'S': {
                            printf("v");
                            break;
                        }
                        case 'D': {
                            printf(">");
                            break;
                        }
                        case 'A': {
                            printf("<");
                            break;
                        }
                        default: {
                            printf("*");
                            break;
                        }
                    }
                }
                else {
                    printf("-");
                }
                printf(" ");
            }
            printf("\n");
        }

        printf("\n");

        //interpretar comandos

        if (!inicio) {

            anterior = orientacao;

            switch(entrada) {
                case ('W'):
                case('w'): {
                    if (y < alturaM) {
                        y ++;
                        orientacao = 'W';
                    }
                    else {
                        orientacao = 'N';
                        bateu = 1;
                    }
                    break;
                }
                case ('S'):
                case('s'): {
                    if (y > 0) {
                        y --;
                        orientacao = 'S';
                    }
                    else {
                        orientacao = 'N';
                        bateu = 1;
                    }
                    break;
                }
                case ('D'):
                case('d'): {
                    if (x < larguraM) {
                    x ++;
                    orientacao = 'D';
                    }
                    else {
                        orientacao = 'N';
                        bateu = 1;
                    }
                    break;
                }
                case ('A'):
                case('a'): {
                    if (x > 0) {
                        x --;
                        orientacao = 'A';
                    }
                    else {
                        orientacao = 'N';
                        bateu = 1;
                    }
                    break;
                }
                case('X'):
                case('x'): {
                    continuar = 0; //nao ta interompendo o while, pq e como concertar? (R: era pq tu botou continuar=1 no while)
                    break;
                }
                default: {
                    printf("comando invalido\n"); //ta aparecendo isso em todos os casos, pq e como concertar? (espaços no scanf, " %c" ao inves de "%c")
                    break;
                }

            }

            //status da movimentação

            if (bateu) {
                printf("bateu");
            }
            else if (anterior=='N'){
                printf("andou!");
            }

            else if (anterior==orientacao){
                printf("andou para frente");
            }

            else if ((anterior=='A' && orientacao=='W') || (anterior=='W' && orientacao=='D') || (anterior=='D' && orientacao=='S') || (anterior=='S' && orientacao=='A')) {
                printf("virou a direita! ");
            }
            else if ((anterior=='A' && orientacao=='S') || (anterior=='S' && orientacao=='D') || (anterior=='D' && orientacao=='W') || (anterior=='W' && orientacao=='A')) {
                printf("virou a esquerda! ");
            }

            else {
                printf("virou para tras! ");
            }

            printf("\n");
        }

        inicio=0;

        //imprimir info tabuleiro e posição autal
        printf("tabuleiro [%d x %d] player (%d, %d)\n\n", larguraM, alturaM, x, y);

        //entrada
        printf("escolha seus movimentos [W, A, S, D ou X para sair]\n");
        printf(">> ");
        scanf(" %c", &entrada);

    }

    printf("\n\nfim da execucao.\n");

}


// main

int main() {
    navegar();
    return 0;
}