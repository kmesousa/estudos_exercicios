#include "logistica.h"

/*- Arquivo logistica.c (Implementação): Deve incluir logistica.h e conter o corpo das funções.
- Giro de estoque: Retorna a divisão de itens_vendidos por estoque_medio.
- Ponto de pedido: Retorna o cálculo (consumo_diario * tempo_reposicao) + estoque_seguranca.*/

float calcular_giro_estoque(int itens_vendidos, int estoque_medio) {
    return itens_vendidos / estoque_medio;
}
int calcular_ponto_pedido(int consumo_diario, int tempo_reposicao, int estoque_seguranca) {
    return (consumo_diario * tempo_reposicao) + estoque_seguranca;
}