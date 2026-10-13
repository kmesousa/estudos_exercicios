#include <stdio.h>
#include <time.h>

/*Demonstração (Prof): "Buffer de Sensores" – Preencher um vetor com 10 leituras de temperatura de uma câmara de conservação de amostras. Iterar sobre ele para encontrar o pico máximo.*/

void buffer_sensores () {
    const int qteTemperaturas = 10;
    int temperaturas[qteTemperaturas], tempAtual;
    int max = 500, min = -200;
    int maior;

    printf("======= BUFFER DE SENSORES =========\n");
    printf("leitura de temperatudas (ºc)\n");
    printf("-------------------------------------\n");

    for (int i = 0; i <qteTemperaturas; i++) {
        tempAtual = rand(); //definir limites da geração aleatoria de numeors
        temperaturas[i] = tempAtual;
        printf("temperatura %d: %d\n", i+1, tempAtual);

        if (i==0) maior = tempAtual;
        else if (maior < tempAtual) maior = tempAtual;
    }

    printf("-------------------------------------\n");
    printf("pico máximo de temperatura: %d C\n", maior);
}


/*Lab 1: "Suavização de Ruído" – Ler 5 distâncias de um sensor ultrassônico. Substituir qualquer valor discrepante (< 0 ou > 1000) pelo valor da posição anterior.*/


/*Lab 2: "Giro de Estoque" – Criar um vetor de 7 posições (domingo a sábado) e registrar a quantidade de insumos hospitalares consumidos, mostrando a média diária ao final.*/


/*Desafio (Casa): "Filtro de Janela Deslizante" – Preencher um vetor de 12 posições com leituras de frequência cardíaca. Gerar um segundo vetor onde cada posição é a média móvel das 3 leituras adjacentes, imprimindo o resultado para análise de tendências.*/

void filtro_janela () {
    int max = 150;
    /*prof definiu:
    valor maximo = 60
    dezenas = 3
    repeticoes = 1
    sequencias = 4

    valor max e repeticoes acho q entendo, apesar de n saber como devo implementar as repetiçoes
    mas oq sao dezenas e sequencias?????

    "segundo vetor onde cada posição é a média móvel das 3 leituras adjacentes" acho q eu nem sei oq isso significa socorro
    MANO EU N ENTENDO OQ TAO PEDIDNO PRA EU FAZER NESSE EXERCICIO SOCORRO*/

}

int main() {
    srand(time(NULL));
    return 0;
}