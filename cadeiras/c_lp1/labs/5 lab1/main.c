#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//para fazer esses exercicios sem alocação dinamica, precisa determinar um tamanho máximo para o vetor/ matriz

void imprimir_vetor (int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i ++) printf("%d ", vetor[i]);
    printf("]");
}

/*1) Considere dois vetores v1 e v2 ordenados de maneira não-decrescente. Crie um programa que mescle v1 e v2 em um terceiro vetor v3, de maneira que v3 também fique ordenado.*/

void  mesclar_ordenado (int vetor1[], int n1, int vetor2[], int n2) {
    int mescladoOrdenado[2000]; //limitar tam de v1 e v2 para 1000
    int i = 0, j = 0, k = 0;

    while (i < n1 || j < n2) {
        if (i < n1 && j <n2) {
            if (vetor1[i] <= vetor2[j]) {
                mescladoOrdenado[k++] = vetor1[i++];
            }
            else mescladoOrdenado[k++] = vetor2[j++];
        }
        else if (i < n1) mescladoOrdenado[k++] = vetor1[i++];
        else mescladoOrdenado[k++] = vetor2[j++];
    }

    //imprimir
    imprimir_vetor(mescladoOrdenado, k);
}

void testar_mesclagem () {
    printf("========== MESCLAR ORDENADOS =========\n");

    const int tam1 = 4, tam2 = 4; //se for pedir pra criar os vetores, tam max de cada é 1000!
    int v1[] = {2, 4, 6, 8};
    int v2[] = {1, 3, 5, 7};

    //imprimir originais
    printf("vetor 1 = ");
    imprimir_vetor(v1, tam1);
    printf("\n");
    printf("vetor 2 = ");
    imprimir_vetor(v2, tam2);
    printf("\n");

    //mesclar e imprimir resultado
    printf("vetor mesclado ordenado = ");
    mesclar_ordenado(v1, tam1, v2, tam2);
    printf("\n");

}
/*2) Escreva um programa que ordene um vetor (inteiros) de maneira não-decrescente.*/

void ordenar_vetor_inteiro (int vetor[], int n) {
    int temp;

    for (int fim = n; fim > 0; fim--) {
        int trocou = 0;
        for (int i = 0; i < fim - 1; i++ ) {
            if (vetor[i] > vetor[i+1]) {
                temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }

    //imprimir
    imprimir_vetor(vetor, n);
}

void testar_ordenacao () {
    const int tamMax = 1000;
    int vetor[tamMax];
    int tam;

    printf("=============== ORDENAR VETOR ================\n");
    printf("quantidade de elementos vetor (max = 1000): ");
    scanf(" %d", &tam);
    printf("digite os elementos do vetor (%d elementos): \n", tam);
    for (int i = 0; i < tam; i ++) {
        printf("[%d] = ", i+1);
        scanf(" %d", &vetor[i]);
    }

    printf("vetor = ");
    imprimir_vetor(vetor, tam);
    printf("\n");

    printf("vetor ordenado = ");
    ordenar_vetor_inteiro(vetor, tam);
    printf("\n");
}

/*3) Escreva um programa que ordene um vetor (strings) de maneira não-decrescente.
 --> um vetor de string pode ser implementado como uma matriz: char vetor_strings[10][1000]. Cada linha funciona como uma matriz*/

 //tentei fazer com função mas n tava reconhendo vetorStrins[i][j], dizia q tava incompleto, pq?
void ordenar_vetor_strings() {
    const int maxString = 250, maxQteStrings=100;
    char vetorStrings[maxQteStrings][maxString];
    int qteStrings = maxQteStrings; //ou iria receber do user
    char temp[maxString];

    //prencher vetor strings manualmente para testes
    strcpy(vetorStrings[0], "oi");
    strcpy(vetorStrings[1], "kme");
    strcpy(vetorStrings[2], "amanha");
    strcpy(vetorStrings[3], "eh");
    strcpy(vetorStrings[4], "um");
    strcpy(vetorStrings[5], "novo");
    strcpy(vetorStrings[6], "dia");

    qteStrings = 7;
    //prencher um vetor de string separando uma string em palavras? como fazer isso?

    printf("=========== ORDENAR VETOR DE STRINGS ============\n");
    printf("o vetor original eh: ");
    for (int i = 0; i < qteStrings; i++) printf("%s ", vetorStrings[i]);
    printf("\n");


    //colocar em ordem, poderia colocar em uma função separada, seria melhor
    for (int fim = qteStrings; fim > 0; fim--) {
        int trocou = 0;
        for (int i = 0; i < fim - 1; i++) {
            int trocar = 0;
            //alternativa
            // if (strcmp(vetorStrings[i], vetorStrings[i+1]) > 0) {
            // trocar = 1;
            // }
            for(int j = 0; j < maxString; j++) {
                if (vetorStrings[i][j]=='\0' && vetorStrings[i+1][j]=='\0') break;
                else {
                    if (vetorStrings[i][j]=='\0') {
                        //trocar = 0;
                        break;
                    }
                    else if (vetorStrings[i+1][j]=='\0') {
                        trocar = 1;
                        break;
                    }
                    else if (vetorStrings[i][j] > vetorStrings[i+1][j]) { //obs assume q Aa vem dps de ab
                        trocar = 1;
                        break;
                    }
                    else if (vetorStrings[i][j] < vetorStrings[i+1][j]) {
                        break; // ordem já decidida, não troca
                    }
                }
            }
            if (trocar) {
                //colocar string i no temp
                strcpy(temp, vetorStrings[i]);
                //colocar string 1+1 na i
                strcpy(vetorStrings[i], vetorStrings[i+1]);
                //colocar string do temp na i+1
                strcpy(vetorStrings[i+1], temp);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }

    //imprimir
    printf("-------------------------------------------------\n");
    printf("strings em ordem nao decrescente: \n");
    for (int i = 0; i <qteStrings; i++) printf("%s\n", vetorStrings[i]);

}

/*4) Escreva um programa em C para contar o número total de elementos duplicados em um vetor.
*/

void contar_duplicados_vetor () {
    const int maxElementos = 1000;
    int vetor[maxElementos], n;
    int escolha;
    int duplicados[maxElementos], qte_duplicados = 0, qte_num_duplicados = 0;

    printf("============= CONTAR DUPLICADOS VETOR ===============\n");
    printf("qte elementos do vetor (max = %d): ", maxElementos);
    scanf(" %d", &n);

    //criar vetor aleatorio ou pelo usuario
    printf("digite \n[0] para gerar vetor aleatorio \n[1] para inserir valores \n>> ");
    scanf(" %d", &escolha);

    if (!escolha) {
        int maxNum = 10, minNum = 0;
        for (int i = 0; i < n; i++) {
            vetor[i] = (rand() % (maxNum - minNum + 1) + minNum);
        }
    }
    else {
        for (int i = 0; i < n; i++) scanf(" %d", vetor[i]);
    }

    //imprimir vetor
    printf("o vetor eh: ");
    for (int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");

    //contar duplicados
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[i]==vetor[j]) {
                qte_duplicados++;
                int checado = 0;
                for (int k = 0; k < qte_num_duplicados; k++) {
                    if (vetor[i]==duplicados[k]) checado = 1;
                }
                if (!checado) {
                    duplicados[qte_num_duplicados++]=vetor[i];
                }
                break;
            }
        }
    }

    qte_duplicados += qte_num_duplicados;

    //imprimir
    printf("a quantidade de elementos duplicados eh %d\n", qte_duplicados);
    printf("a quantidade de numeros duplicados eh %d\n", qte_num_duplicados);
    printf("os numeros que foram duplicados sao: ");
    for (int i = 0; i < qte_num_duplicados; i++) printf("%d ", duplicados[i]);

    printf("\n");

}


/*5) Escreva um programa C para contar o número total de palavras em uma string usando loop. (mais dificil segundo o prof)*/

int contar_palavras_string (char string[], int tamString) {
    //const int maxTamString = 1000;
    // char string[maxTamString];
    // int tamString = maxTamString; //ou receber depois

    char especiais[] = {',', '.', ';', '(', ')', '-'};
    int qteEspeciais = strlen(especiais);

    //strcpy(string, "oi kme , amanha eh um novo dia ( denovo ).");

    int qtePalavras = 0;

    int ehCharPalavra = 0;
    int ehEspaco = 0;
    int ehEspecial = 0;

    for (int i = 0; i < tamString+1; i++) {

        //printf("indice %d \nchar %c \nqte palavras %d \nehcharpalavra %d \nehespaco %d \nehespecial %d", i, string[i], qtePalavras, ehCharPalavra, ehEspaco, ehEspecial);
        if (string[i]=='\0') { //só é usado pq i < tamString + 1
            if (ehCharPalavra) qtePalavras++;
            break;
        }

        ehEspaco = 0;
        ehEspecial = 0;

        if (string[i]==' ') ehEspaco = 1;

        else {
        for (int j = 0; j < qteEspeciais; j++) {
            if (string[i]==especiais[j]) {
                ehEspecial = 1;
            }
        }
        }

        if (!ehEspaco && !ehEspecial) ehCharPalavra = 1;

        if (ehCharPalavra && (ehEspecial || ehEspaco)) {
            qtePalavras++;
            ehCharPalavra = 0;
        }

        /*ir iterando sobre string
        enquanto nao for espaço e nao for char especial, considerar palavra
        se econtrar espaço ou espacial, e palavra == 1, somar qte de palavras e palavra = 0
        se encontrar espaço ou especial, mas palavra == 0, nao somar qte de palavras*/
    }

    // if (ehCharPalavra) qtePalavras++; //caso nao usasse i < tamString + 1

    return qtePalavras;

}

void testar_contar_palavras () {
    char stringTeste[] = {"oi kme , amanha eh um novo dia (denovo)."};
    int tamString = strlen(stringTeste);

    printf("=========== CONTAR PALAVRAS DE UMA STRING ============\n");
    printf("a string eh: %s\n", stringTeste);

    int qtePalavras = contar_palavras_string(stringTeste, tamString);
    printf("a quantidade de palavras eh: %d\n", qtePalavras);
}


/*6) Escreva um programa que armazene uma matriz em um vetor e depois permita fazer as seguintes operações por meio de funções:
a) acessar uma posição da matriz indicando linha e coluna
b) obter a diagonal principal da matriz
c) obter todos os elementos de determinada coluna da matriz
d) obter todos os elementos de determinada linha da matriz

idx = (i*col) + j
*/

//obter diagonal principal
void ver_diagonal (int lin, int col, int matrizFake[]) {
    int idx;
    int soma = 0;
    //int diagonal[1000];

    printf("a diagonal principal eh: \n");
    for (int i = 0; i < lin; i ++) {
        idx = (i*col) + i;
        int num = matrizFake[idx];
        soma += num;
        //diagonal[i] = num;

        //imprimir simulando outros elementos em branco
        printf("[");
        for (int j = 0; j < i; j++) printf("  "); //tbm precisaria pegar min e max pra determinar espaço, mas deixa assim
        printf(" %d", num);
        for (int j = i+1; j < col; j++) printf("  ");
        printf("]\n");

    }

    printf("a soma da diagonal eh %d\n", soma);
}

//obter todos os elementos de determinada linha
void ver_linha (int lin, int col, int matrizFake[]) {
    int soma=0, num, idx;

    printf("escolha uma linha: \n");
    int linha;
    scanf("%d ", &linha);

    if (linha >= lin || linha < 0) printf("a linha nao existe\n");
    else {
        printf("a linha %d eh: \n", linha);
        for (int j = 0; j < col; j ++) {
            idx = (linha*col) + j;
            num = matrizFake[idx];
            soma += num;
            printf(" %d", num);
        }
        printf("\na soma da linha %d eh %d\n", linha, soma);
    }

}


//obter todos os elementos de determinada coluna
void ver_coluna (int lin, int col, int matrizFake[]) {
    int soma=0, num, idx;

    printf("escolha uma coluna: ");
    int coluna;
    scanf(" %d", &coluna);

    if (coluna >= col || coluna < 0) printf("a coluna nao existe\n");
    else {
        printf("a coluna %d eh: \n", coluna);
        for (int i = 0; i < lin; i ++) {
            idx = (i*col) + coluna;
            num = matrizFake[idx];
            soma += num;
            printf("%d\n", num);
        }
        printf("a soma da coluna %d eh %d\n", coluna, soma);
    }
}

//imprimir vetor como matriz
void imprimir_matriz (int lin, int col, int vetor[], int max, int min) {
    //usar max e min pra determinar a maior quantidade de digitos, e usar isso pra alinhas as colunas (opicional)
    int idx = 0;
    for (int i = 0; i < lin; i++) {
        printf("[");
        for (int j = 0; j < col; j++) {
            //idx = (i*col) + j; //alterantiva
            printf(" %d", vetor[idx]);
            idx++;
        }
        printf("]\n");
    }
}


void armazenar () {
    const int maxElementos = 1000;
    int lin, col;
    int matrizFake[maxElementos], idx = 0, num;
    int escolha, valido = 1;
    int maxNum, minNum;

    //tamanho da matriz
    printf("=============== MATRIZ ===================\n");
    printf("obs. o max de elementos eh %d\n", maxElementos);
    printf("quantidade de linhas: ");
    scanf(" %d", &lin);
    printf("quantidade de colunas: ");
    scanf(" %d", &col);

    if (lin*col > maxElementos) valido = 0;

    //pedir vetor ou perguntar se quer gerar aleatorio
    printf("------------------------------------------\n");
    printf("[0] para matriz aleatoria \n[1] para inserir valores \n>> ");
    scanf(" %d", &escolha);

    switch (escolha)
    {
    case 0: //gerar matriz aleatoria
        maxNum = 100, minNum = 0;
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                num = (rand() % (maxNum - minNum + 1) + minNum);
                matrizFake[idx++] = num;
            }
        }
        break;
    default:
        printf("------------------------------------------\n");
        printf("digite %d valores para a matriz\n", lin*col);
        //int maxNum, minNum; //descobrir o maior e menor valor
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                scanf(" %d", &num);
                if (idx==0) {
                    maxNum = num;
                    minNum = num;
                }
                else {
                    if (maxNum < num) maxNum = num;
                    if (minNum > num) minNum = num;
                }
                matrizFake[idx++] = num;
            }
        }
        break;
    }

    //imprimir vetor como matriz
    printf("------------------------------------------\n");
    imprimir_matriz(lin, col, matrizFake, maxNum, minNum);

    //operações
    if (lin==col) {
        printf("------------------------------------------\n");
        ver_diagonal(lin, col, matrizFake);
    }
    printf("------------------------------------------\n");
    ver_linha(lin, col, matrizFake);
    printf("------------------------------------------\n");
    ver_coluna(lin, col, matrizFake);
}


int main () {
    srand(time(NULL));
    printf("1");
    testar_mesclagem();
    printf("2");
    testar_ordenacao();
    printf("3");
    ordenar_vetor_strings();
    printf("4");
    contar_duplicados_vetor();
    printf("5");
    testar_contar_palavras();
    printf("6");
    armazenar();
    return 0;
}