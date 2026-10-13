#include <stdio.h>

/*
Lab 1: Cálculo de Rota Modular
Objetivo: Compreender a criação de funções com e sem retorno e o escopo de variáveis locais. A regra principal é que a função main não deve fazer nenhum cálculo logístico, servindo apenas como interface de entrada/saída e coordenadora.

Especificação:
- Crie uma função float calcular_combustivel(float distancia, float consumo, float preco_litro). Ela deve calcular a quantidade de litros necessários e multiplicar pelo preço do litro, retornando o custo total com combustível.
- Crie uma função float calcular_desgaste(float distancia). Assuma que o custo de manutenção/desgaste do caminhão é de R$ 0,80 por quilômetro rodado. A função retorna este custo.
- Na função main, declare as variáveis locais para receber a distância da viagem, o consumo do caminhão (km/l) e o preço do combustível.
- A main deve chamar as duas funções, somar os retornos para obter o custo total do frete e exibir o resultado na tela.

Lab 2: Ressuprimento do SUS
Objetivo: Praticar funções matemáticas simples que retornam valores booleanos (0 ou 1) para tomada de decisão lógica.

Especificação:
- Crie a função com a seguinte assinatura: int precisa_repor(int estoque_atual, int consumo_medio_diario).
- Se o resultado for menor que 5 dias, a função deve retornar 1 (Verdadeiro/Alerta). Caso contrário, deve retornar 0 (Falso/Estoque Seguro).
- Na função main, peça ao usuário para informar o estoque de um medicamento e a média de caixas usadas por dia.

Lab 3: Distribuição de Carga
Objetivo: Trabalhar com divisão, arredondamento e funções que processam parâmetros para definir dimensionamento de frota.

Especificação:
- Crie a função int calcular_veiculos(float peso_total, float capacidade_caminhao).
- Na main, capture o peso total dos suprimentos a serem transportados (ex: vacinas, seringas) e a capacidade máxima do veículo escolhido.
- Exiba na tela a quantidade exata de veículos que precisarão ser despachados.

Lab 4: Simulador de Cadeia de Suprimentos
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