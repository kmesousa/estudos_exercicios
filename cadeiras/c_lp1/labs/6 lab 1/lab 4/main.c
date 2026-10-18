#include <stdio.h>
#include "logistica.h"
//#include "logistica.c" //nao precisa ser chamado

/*Lab 4: Simulador de Cadeia de Suprimentos
Objetivo: Implementar a modularização física separando o código em múltiplos arquivos (.h e .c), além de reforçar funções mais complexas.

Especificação:

- Arquivo logistica.h (Cabeçalho): Deve conter apenas as declarações (protótipos) das funções.
- float calcular_giro_estoque(int itens_vendidos, int estoque_medio);
- int calcular_ponto_pedido(int consumo_diario, int tempo_reposicao, int estoque_seguranca);
- Arquivo logistica.c (Implementação): Deve incluir logistica.h e conter o corpo das funções.
- Giro de estoque: Retorna a divisão de itens_vendidos por estoque_medio.
- Ponto de pedido: Retorna o cálculo (consumo_diario * tempo_reposicao) + estoque_seguranca.
- Arquivo main.c (Programa Principal): Deve incluir <stdio.h> e "logistica.h". Aqui, crie um menu interativo simples:

- Opção 1: Calcular Giro de Estoque.
- Opção 2: Calcular Ponto de Pedido.
- Opção 3: Sair.*/

int main () {

    printf("======= SIMULADOR DE CADEIA DE SUPRIMENTOS ========");
    printf("[1] calcular giro de estoque\n");
    printf("[2] calcular ponto de pedido\n");
    printf("[3] sair\n");

    int opcao;

    printf(">> ");
    scanf(" %d", &opcao);

    switch (opcao)
    {
    case 1:
        float itens, estoque_medio;
        printf("itens vendidos: ");
        scanf(" %f", &itens);
        printf("estoque medio: ");
        scanf(" %f", &estoque_medio);
        float r = calcular_giro_estoque(itens, estoque_medio);
        printf("giro estoque = %f", r);
        break;

    case 2:
        break;

    default:
        break;
    }

    printf("fim do programa.");

    return 0;
}