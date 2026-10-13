#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*Lab 1: "Simulador de Ping" – Usar um laço for para simular o envio de 4 pacotes ICMP, gerando valores de latência aleatórios e calculando a média.*/

void simular_ping () {

    const int tam = 4;
    int max = 100000;
    int total = 0, media;
    int pacotes[tam];


    printf("========= SIMULADOR DE PING ==========\n");
    for (int i = 0; i < 4; i++) {
        pacotes[i] = rand() % max;
        total += pacotes[i];
        printf("pacote %d: %d (ms)\n", i+1, pacotes[i]);
    }

    media = total/tam;

    printf("--------------------------------------\n");
    printf("total: %d (ms) \nmedia: %d (ms)\n\n", total, media);
}


/*Lab 2: "Handshake (Retry)" – Usar um while para simular a conexão a um servidor. O programa pede uma "Chave de Acesso" e continua em loop até que o usuário acerte ou erre 3 vezes (Timeout).*/

void handshake () {
    int chaveNumerica, chuteAtual; //poderia colocar a chave como umsa senha, mas prefiro assim para ser gerada aleatoriamente
    int qteTentativas = 5;
    int cont = 0;
    int numeroMax = 10;
    int acertou = 0;

    chaveNumerica = rand() % (numeroMax + 1);

    printf("=============== HANDSHAKE ==============\n");
    printf("insira a chave de acesso (0 - %d) \n%d tentativas\n", numeroMax, qteTentativas); //poderia ficar limpado a tela toda hora para atualizar colocando o numero de tentativas restantes
    printf("--------------------------------------\n");

    while (cont < qteTentativas && !acertou) {
        cont++;

        printf("tentativa %d: ", cont);
        scanf(" %d", &chuteAtual);

        if (chuteAtual==chaveNumerica) {
            acertou = 1;
        }
    }

    if (acertou) {
        printf("conexao realiza na %d tentativa\n", cont);
    }
    else {
        printf("TIMEOUT: conexao falhou apos %d tentativas\n", cont);
    }
    printf("(chave de acesso = %d)\n", chaveNumerica);

    printf("\n");

}

/*Lab 3: "Parser de Logs" – Usar um do/while para ler códigos de transações financeiras. O loop encerra quando o código 0 é recebido, imprimindo o total de operações suspeitas contabilizadas.*/

//duvida: todas as operaçoes inseridas sao suspeitas ou eu vou ter q diferenciar operações normais das suspeitas? se o ultimo caso, entao qual o critério?
//queria fazer tipo, ele pode ou gerar os codigos aleatoriamente ou pedir pra o usuario inserir, se o usuario nao inserir nada e só apertar enter, entao ele gera aleatoriamente, limpa a tela para mostrar tudo até o ultimo valor inserido
//acho que eu ia precisar de um vetor alocação dinamica pra poder fazer essa parte de limpar a tela, será se nao tem como só limpar a ultima linha?
//acho esse exercicio nem precisa usar vetor ou geração de numero,  é só do/while msm, o resto é opcional, mas acho legal tentar fazer

void paser_de_logs() {
    int cont = 0;
    int max = 9999, min = 1; //por convensão, os códigos das transações terão 4 dígitos, 1 sera mostrado como 0001, por exemplo (isso seria caso fizesse a geração aleátoria dos números, acabei desistindo, mas deixarei anotado caso queira implementar posteriormente)
    int codigoAtual;

    printf("============== PASER DE LOGS ==============\n");
    printf("leitor de codigos de transacoees financeiras\n");
    printf("-------------------------------------------\n");

    do {
        cont ++;
        printf("transacao %d: ", cont);
        scanf(" %d", &codigoAtual);
    }
    while (codigoAtual != 0);

    printf("-------------------------------------------\n");
    printf("foram contabilizadas %d operacoes suspeitas\n\n", cont);
}


/*Lab 4: "Traceroute Textual" – Simular o salto de pacotes por roteadores. Para cada salto (de 1 até N), ler o nome do roteador e o tempo de resposta, interrompendo o laço imediatamente com break se o tempo for negativo (simulando perda de rota).*/

void traceroute_textual () {
    int tempo, idroteador[4], cont = 0;
    int min = 0, max = 255;

    //gerar nome e tempo aleatoriamente?? ou fazer normal pedindo pra inserir msm?

    printf("======================== TRACEROUTE TEXTUAL ========================\n");
    printf("simulador de salto de pacotes por roteadores\n");
    printf("--------------------------------------------------------------------\n");

    do {

        //gerar IP do roteador (4 numeros de 0 a 255
        for (int i = 0; i < 4; i++) {
            idroteador[i] = rand() % (max - min + 1) + min;
        }

        cont ++;
        printf(" EVENT_ID %d [roteador]: ", cont);
        for (int i = 0; i < 4; i++) { //imprimir o IP do roteador formatdo, numero por numero, separado por ponto
            printf("%d", idroteador[i]);
            if (i < 3) {
                printf(".");
            }
        }
        printf(" [tempo de resposta]: "); //pedir tempo
        scanf(" %d", &tempo);
    }
    while (tempo >= 0); //checar se o tempo é negativo, se for, o laço é interrompido

    /*possíveis melhorias:
    - alinhar as linhas
    */

    printf("--------------------------------------------------------------\n");
    printf("perda de rota detectada no roteador %d\n\n", cont);
}


int main() {
    srand(time(NULL));
    simular_ping();
    handshake();
    paser_de_logs();
    traceroute_textual();
    return 0;
}