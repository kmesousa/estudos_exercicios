#include <stdio.h>

/*
Lab 1: Cálculo de Rota Modular
Objetivo: Compreender a criação de funções com e sem retorno e o escopo de variáveis locais. A regra principal é que a função main não deve fazer nenhum cálculo logístico, servindo apenas como interface de entrada/saída e coordenadora.

Especificação:
- Crie uma função float calcular_combustivel(float distancia, float consumo, float preco_litro). Ela deve calcular a quantidade de litros necessários e multiplicar pelo preço do litro, retornando o custo total com combustível.
- Crie uma função float calcular_desgaste(float distancia). Assuma que o custo de manutenção/desgaste do caminhão é de R$ 0,80 por quilômetro rodado. A função retorna este custo.
- Na função main, declare as variáveis locais para receber a distância da viagem, o consumo do caminhão (km/l) e o preço do combustível.
- A main deve chamar as duas funções, somar os retornos para obter o custo total do frete e exibir o resultado na tela.*/

float calcular_combustivel (float distancia, float consumo, float preco_litro) {
    float litros_necessarios = distancia / consumo;
    float preco_total = litros_necessarios * preco_litro;

    return preco_total;
}

float calcular_desgaste (float distancia) {
    float custo_por_km = 0.8;
    float custo_total = distancia * custo_por_km;

    return custo_total;
}
/*Lab 2: Ressuprimento do SUS
Objetivo: Praticar funções matemáticas simples que retornam valores booleanos (0 ou 1) para tomada de decisão lógica.

Especificação:
- Crie a função com a seguinte assinatura: int precisa_repor(int estoque_atual, int consumo_medio_diario).
- Se o resultado for menor que 5 dias, a função deve retornar 1 (Verdadeiro/Alerta). Caso contrário, deve retornar 0 (Falso/Estoque Seguro).
- Na função main, peça ao usuário para informar o estoque de um medicamento e a média de caixas usadas por dia.*/

int precisa_repor (int estoque_atual, int consumo_medio_diario) {
    int resultado;

    if (estoque_atual/ consumo_medio_diario < 5) return 1;
    else return 0;
}

/*Lab 3: Distribuição de Carga
Objetivo: Trabalhar com divisão, arredondamento e funções que processam parâmetros para definir dimensionamento de frota.

Especificação:
- Crie a função int calcular_veiculos(float peso_total, float capacidade_caminhao).
- Na main, capture o peso total dos suprimentos a serem transportados (ex: vacinas, seringas) e a capacidade máxima do veículo escolhido.
- Exiba na tela a quantidade exata de veículos que precisarão ser despachados.*/

int calcular_veiculos (float peso_total, float capacidade_caminhao) {
    int veiculos_necessarios = (int) (peso_total/capacidade_caminhao);

    return veiculos_necessarios;
}


int main () {

    printf("===== CALCULO DE ROTA MODULAR ===== 1\n");
    float distancia, consumo, preco_litro;

    printf("distancia da viagem (km): ");
    scanf(" %f", &distancia);
    printf("consumo do caminhão (km/l): ");
    scanf(" %f", &consumo);
    printf("preco do litro do combustivel (R$): ");
    scanf(" %f", &preco_litro);

    float custo_comb = calcular_combustivel(distancia, consumo, preco_litro);
    float custo_manut = calcular_desgaste(distancia);
    float custo_total = custo_comb + custo_manut;

    printf("gasto com combustivel = %f R$", custo_comb);
    printf("gasto com manutencao = %f R$", custo_manut);
    printf("o custo total eh %f R$ \n", custo_total);

    return 0;
}