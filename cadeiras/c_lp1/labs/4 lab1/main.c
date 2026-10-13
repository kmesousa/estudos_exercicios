#include <stdio.h>
#include <string.h>

/*Lab 1: "Caption Filter" – Receber uma string representando a descrição textual (caption) de um exame médico e usar funções nativas para buscar a presença de palavras-chave como "anomalia" ou "lesão".*/

void caption_filter() {

}


/*Lab 2: "Distância de Hamming" – Ler duas strings de mesmo tamanho representando sequências genéticas (A, C, G, T) e contar em quantas posições os caracteres diferem.*/


/*Desafio (Casa): "Cifra de César" – Ler uma mensagem investigativa sensível e aplicar um deslocamento de +3 na tabela ASCII em cada caractere para criptografar o texto antes do armazenamento.*/

void cifra_de_cesar() {
    const int tamMax = 1000;
    char msg[tamMax];
    int deslocamento = 3;
    int i = 0;
    int codigoAscii;
    int limiteMai = 'Z', limiteMin = 'z';

    printf("==================== CIFRA DE CESAR ===================\n");
    printf("digite a mensagem a ser criptografada (max %d char)\n>> ", tamMax -1);
    scanf(" %[^\n]", msg);

    printf("--------------------------------------------------------\n");
    printf("mensagem criptografada com deslocamento %d:\n", deslocamento);

    while (msg[i] != '\0') {
        codigoAscii = msg[i];

        // se nao for alfabetico, deixar como está
        if (msg[i] == ' ') {
            printf(" ");
        }
        else {
            //gerar deslocamento
            if (codigoAscii + deslocamento > limiteMai || codigoAscii + deslocamento > limiteMin ) {
                printf("%c", codigoAscii + deslocamento - ('a' - 'z'));
            }
            else {
            printf("%c", codigoAscii + deslocamento);
            }
        }
        i ++;
    }

}

int main() {
    cifra_de_cesar();
    return 0;
}