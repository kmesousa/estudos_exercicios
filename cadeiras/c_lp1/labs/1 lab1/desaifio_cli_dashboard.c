/*  "CLI Dashboard" – Criar um mini painel no terminal que leia as iniciais de um operador e seu ID, imprimindo um crachá virtual estilizado apenas com caracteres textuais.*/

#include <stdio.h>

void cracha_virual (void) {
    char nome;
    int id;

    //obter dados
    printf("====== CRACHA VIRTUAL =====\n");
    printf("nome: ");
    scanf("%s",&nome);
    printf("id: ");
    scanf("%d",&id);

    //imprimir cracha
    //queria colocar para pegar o tamanho do nome e do id e usar como base para definir o tamanho do cracha, mas não sei como fazer isso ;-; (sdds do len())
    // int x;
    // for (x = 0, x<=50, x++);
    //     printf("*")

}

int main () {

    cracha_virual();

    return 0;
}