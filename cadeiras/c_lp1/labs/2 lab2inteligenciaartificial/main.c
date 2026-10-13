#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*Lab 1: "Árvore de Decisão de Triagem Médico-Hospitalar" – Desenvolver um sistema interativo em terminal que coleta respostas binárias (1 para Sim, 0 para Não) referentes a múltiplos sintomas (febre alta, tosse persistente, dor no peito, falta de ar). Demonstrar o encadeamento de estruturas condicionais if/else e operadores lógicos (&&, ||) para direcionar o paciente a níveis de prioridade de atendimento (emergência, urgência ou ambulatório) e gerar um diagnóstico preliminar básico.*/

void triagem_hospilatar() {

    //checar prioridade
    int qte_sintomas = 0;
    int prioridade;

    //titulo
    printf("======== TRIAGEM HOSPITALAR ==========\n");
    printf("coleta de simtomas, marque: \nSIM [1] ou NÃO [0]\n");
    printf("=======================================\n");

    //coleta de sintomas
    printf("febre alta: ");
    printf("tosse persistente: ");
    printf("do no peito: ");
    printf("falta de ar: ");
    printf("coriza: ");
    printf("calafrio: ");
    printf("dor de cabeça: ");

    //diagnostico preliminar básico

}


/*Lab 2: "Classificador Multiclasse de Estágios de Anomalia" – Receber um valor de pontuação contínuo ou percentual (0 a 100), simulando o parâmetro de saída (score de confiança) de um modelo de Inteligência Artificial de visão computacional. Construir uma estrutura de condicionais aninhadas (if / else if / else) para categorizar o nível de gravidade da patologia (ex.: retinopatia ausente, leve, moderada, severa ou proliferativa), validando limites e tratando entradas inválidas.*/

//mano nem entendi esse????

void classificar_anomalias() {


}


/*Desafio (Casa): "Engine de Validação Heurística de Movimentos no Xadrez" – Ler as coordenadas Cartesianas numéricas (X, Y) de uma peça Cavalo e de uma peça Peão em um tabuleiro 8x8. Sem utilizar laços de repetição ou bibliotecas externas, aplicar exclusivamente expressões lógicas condicionais baseadas nas regras geométricas do movimento do Cavalo (diferença absoluta de 2 unidades em um eixo e 1 unidade no outro) para determinar se a peça Peão está sob alcance direto de ataque no próximo turno.*/

void validacao_xadres() {

    //variaveis
    int xcavalo, ycavalo, xpeao, ypeao;
    int tabuleiro = 8;

    //entrada
    printf("========== VALIDACAO XADRES =============\n");
    printf("indique as posições das peças (x,y)\n");
    printf("posicao cavalo: ");
    scanf(" %d %d" &xcavalo, &ycavalo);
    printf("posicao peão: ");
    scanf(" %d %d" &xpeao, ypeao);

    //calculo

    //imprimir resultado

}

//selecionar

void selecionar() {

}

// main

int main() {
    selecionar();
    navegar();
    return 0;
}