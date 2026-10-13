#include <stdio.h>
#include <math.h> //para o desafio do projetil simples

/*Lab 1: "Dano Base" – Calcular o dano final de um ataque: (Força * 1.5) + (Arma - Defesa_Inimigo).*/

void dano_base() {
    float forca, arma, defesaInimigo;
    float danoBase;

    //entrada de dados
    printf("======= CALCULAR DANO BASE =======\n");
    printf("forca: ");
    scanf("%f", &forca);
    printf("arma: ");
    scanf("%f", &arma);
    printf("desefa inimigo: ");
    scanf("%f", &defesaInimigo);

    //calculo do dano base
    danoBase = (forca * 1.5) + (arma - defesaInimigo);

    //impressao
    printf("o dano base eh %.2f", danoBase);

}

/*Lab 2: "Conversor de Moeda" – O jogador coletou "Ouro". Converter o valor para Prata e Cobre (ex: 1 Ouro = 10 Prata = 100 Cobre) usando operadores de divisão e módulo (%).*/

void conversor_ouro() {
    int ouro, prata, cobre;
    int valorprata = 10, valorcobre = 100; //para cada 1 ouro

    //entrada de dados

    printf("======= CONVERSOR DE MOEDA =======\n");
    printf("ouro coletado: ");
    scanf("%d", &ouro);

    //conversao para cobre e prata

    prata= ouro * valorprata;
    cobre = ouro * valorcobre;

    //impressao
    printf("----------------------\n");
    printf("ouro: %d\n", ouro);
    printf("prata: %d\n", prata);
    printf("cobre: %d\n", cobre);

}

//valor em cobre para ser convertido em prata em ouro
void conversor_cobre() {
    int ouro, prata, cobre;
    int valorouro = 100, valorprata = 10; //quantos ouros para 1 de cada

    //entrada de dados

    printf("======= CONVERSOR DE MOEDA =======\n");
    printf("cobre coletado: ");
    scanf("%d", &cobre);

    //conversao para ouro e prata

    ouro = cobre/valorouro;
    cobre -= ouro*valorouro;
    prata = cobre/valorprata;
    cobre -= prata*valorprata;

    //impressao
    printf("----------------------\n");
    printf("ouro: %d (%d * %d = %d) \n", ouro, ouro, valorouro, ouro*valorouro); //5 (5 * 100 = 500)
    printf("prata: %d (%d * %d = %d) \n", prata, prata, valorprata, prata * valorprata);
    printf("cobre: %d (%d * %d = %d) \n", cobre, cobre, 1, cobre);
}

/* Desafio (Casa): "Projétil Simples" – Ler a velocidade inicial de um projétil e o tempo de voo. Calcular a posição final (Y) considerando a gravidade, exigindo o uso da biblioteca <math.h>.
Y = V0 * tempo - (1/2 * gravidade * tempo^2) */

void projetil() {
    float v0, Yf;
    int tempo;
    const int gravidade = 10;

    //entrada de dados

    printf("============ PROJETIL ============\n");
    printf("velocidade inicial(m/s): ");
    scanf("%f", &v0);
    printf("tempo de voo (segundos): ");
    scanf("%d", &tempo);

    //calculo
    Yf = v0 * tempo - (0.5 * gravidade * pow(tempo, 2));

    //impressao
    printf("posicao final(m): %.2f", Yf);

}

//selecionar problema

void selecionar() {
    int opcao;
    int continuar = 1;
    int resposta = 0;

    while (continuar==1) {
        printf("======= SELECIONAR PROBLEMA ======\n");
        printf("[1] dano base\n");
        printf("[2] conversor de moeda\n");
        printf("[3] projetil simples\n");
        printf("[0] sair\n");

        printf("===================================\n");
        printf("selecione o problema:\n>> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            dano_base();
            break;
        case 2:
            conversor_ouro();
            break;
        case 3:
            projetil();
            break;
        default: {
            printf("fim da execucao.\n");
            continuar = 0;
            break;
            }
        }
        if (continuar != 0) {
             printf("\n===================================\n");
             printf("digite [1] para continuar\n>>");
             scanf("%d", &resposta);
        }

        if (resposta != 1) {
            continuar = 0;
        }
        printf("\n\n");

    }

}

int main()
{
    selecionar();
    return 0;
}