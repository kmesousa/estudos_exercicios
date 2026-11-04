#include <stdio.h>
#include <stdlib.h>

int main () {
    int *v; //ponteiro v
    int n; //tam do vetor
    printf("\nTamanho do vetor? ");
    scanf("%d",&n);

    /* ------------- Alocando dinamicamente o espaço necessário -------------
  1 - Calcular o número de bytes necessários
  primeiramente multiplicamos o número de componentes do vetor pela
  quantidade de bytes que é dada pelo comando sizeof,
  portanto temos:
  num_componentes * sizeof(float)

  2 - Reservar a quantidade de memória
  usamos malloc para reservar essa quantidade de memória,
  então temos:
  malloc(num_componentes * sizeof(float))

  3 - Converter o ponteiro para o tipo de dados desejado
  como a função malloc retorna um ponteiro do tipo void,
  precisamos converter esse ponteiro para o tipo da nossa variável, no caso float,
  por isso usamos o comando de conversão explicita:
  (float *)

  4 - juntando tudo e atribuindo em v temos o comando abaixo: */

    v = (int *) malloc( n*sizeof(int) );

    if( v==NULL ) { //ou if(!arr)
        printf("nao foi possivel inicializar o vetor.");
        return -1;
    }

    //Armazenando os dados em um vetor
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
        scanf("%d",&v[i]);
    }

    // ------ Percorrendo o vetor e imprimindo os valores ----------
    printf("\n*********** Valores do vetor dinamico ************\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", v[i], &v[i]);
    }

    //liberando o espaço de memória alocado
    free(v); //pq precisa desalocar memoria? oq exatamente é isso?
    //getch(); //o que isso faz?

    return 0;
}