#include <stdio.h>

/*enunciado
Um labirinto qualquer pode ser representado em termos de espaços em branco e *. As paredes são representadas com * e os espaços em branco como caminho. Existe ainda uma marcação da posição inicial com a letra E e da saída com a letra S. Considere ainda que o labirinto pode ser de qualquer tamanho e que os movimentos só podem ser realizados para a casa adjacente, a 1 casa de  distância (8 direções).
Obs: não pode andar por fora ;)

Ex: Labirinto 10x10
*********S
*   *    *
* * * ** *
* *   *  *
* *** ** *
*   *    *
*** * ** *
*   *    *
* *** ****
E********

*********S
*345*2345*
*2*6*1** *
*1*789*  *
*9*** ** *
*876*    *
***5* ** *
*234*    *
*1*** ****
E********

*********S
*---*----*
*-*-*-** *
*-*---*  *
*-*** ** *
*---*    *
***-* ** *
*---*    *
**** ****
E********

*********S
* - * ---*
*-*-*-** *
*-* - *  *
*-*** ** *
* - *    *
***-* ** *
* - *    *
*-*** ****
E********


Dado este labirinto, implemente:
a) um função, interativa, para encontrar um caminho da entrada até a saída. No fim, a função deve imprimir as posições do caminho.*/

// variação de linha e de coluna para cada uma das 8 possibilidades de movimentação
const int DR[8] = { -1, -1,  0,  1,  1,  1,  0, -1 };
const int DC[8] = {  0,  1,  1,  1,  0, -1, -1, -1 };

/*movimentações
    upl up upr
    l    x   r
    dl  dwn dr

    =

    8  1  2
    7  0  3
    6  5  4

    =
    0,0 0,1 0,2
    1,0 1,1 1,2
    2,0 2,1 2,2

    //sentido tentativas: up right down left

*/

//       CRIAR E LIBERAR MATRIZ LABIRINTO A PARTIR DE STRING

char** create_labyrinth(int ROWS, int COLS, const char *source[]) {

    /* monta o labirinto na memória a partir de um array de strings
       retorna o char ** alocado, ou NULL se der erro */

    // 1. alocar o array de ponteiros: LINES * sizeof(char *)
    // 2. para cada linha i:
    //      2.1 conferir se strlen(source[i]) == COLS
    //          (senão: liberar o que já foi alocado e retornar NULL)
    //      2.2 alocar COLS + 1 chars (o +1 é o '\0', se quiser tratar a linha como string)
    //      2.3 copiar source[i] para a linha alocada
    // 3. checar o retorno de cada malloc (NULL = sem memória)
    // 4. retornar o array de ponteiros

    //labirinto vai ser um ponteiro para ponteiros, logo ** ai,




    return NULL;
}

void free_labyrinth(int ROWS, char **labyrinth) {
    for (int i = 0; i < ROWS; i++) free(labyrinth[i]);
}


//             CHECAGENS INCIAIS NO LABIRINTO

int validate (int ROWS, int COLS, char **labyrinth, char enter_char, char exit_char, char wall) {
    int valid = 0;

    //checar se tem exatamente 1 saída
    //checar se tem exatamente 1 entrada

    //checar se todas as linhas possuem o mesmo tamanho (caso create laby for descartado dps)

    return valid;
}


int find_position (char obj, int* positions, int ROWS, int COLS, char** labyrinth) {
    /*finds the first ocurrence of a char in the labyrinth matrix and returns its x and y, returns 1 if found else 0*/

    int valid = 0;

    //percorer a matriz do labirinto passado por referencia
    //encontrar a primeira incidencia do caractere usado para o obj (ex entrada saída)
    //criar um vetor e passar para o ponteiro positions, com x e y do obj encontrado
    return valid;

}

//              INFORMAÇÕES DAS CELULAS

void create_info_matrix (int ROWS, int COLS, char **labyrinth) {

    // 0 = nao visitada
    // - 1 = parede
    // 1 a 9 prox movimentação

}

//               MOVIMENTAÇÃO

void is_valid_path (int position, int movement) {

}

//               PILHA DA ROTA

void create_route() { //nao sei se essa função realmente seria necessária, analisar
}

void add_to_route(int *route, int *route_len, int cell) {
    /* push: coloca a casa no fim da rota */
}

int remove_from_route(int *route, int *route_len) {
    /* pop: tira a última casa da rota e devolve ela */

    return -1;
}

int solve_labyrinth(int ROWS, int COLS, char** labyrinth, char exit_char, char enter_char, char walls) {

    //validate lab
    validate(ROWS, COLS, labyrinth);

    //find enter positions and exit positions
    int EXIT, ENTER;


    //começar do enter e tentar sollucionar
    int atual[2] = ENTER;
    int route; //array de posições percorridas, array de array duplos, vai sofrer várias alterações

    //tentar ir na sequencia, se não conseguir (tiver parece, limite do labirinto ou já foi visitada) tentar a proxima

    //registrar movimento no array da rota

    //se chegar num limite, voltar para a anterior
    // como vai saber qual é a anterior? tem um array da rota

    //remover o que do qual está retornando do array da rota
    //checar qual foi o movimento feito reversamente, para saber qual seria o próximo movimento desse (aka saber quais movimentos já foram realizados ou skipados, continuar de onde parou)

    //se chegar no fim da sequência, retornar novamente

    //fazer até chegar na EXIT

    //ou até chegar de volta no ENTER e não ter mais movimento a ser realizado

    //imprimir status

    //observações sobre as já visitadas: eu posso fazer o retorno para uma já visitada, a partir de voltar na rota, mas não posso a partir dair ir para frente para uma já visitada

   //se tiver solução:

   //opicional: eliminar movimentações desnecessárias, procurar atalhos na rota, após ter a rota completa

    //imprimir a rota
    //imprimir o labirinto com a saída em realce

    //opcicional: definir dinamicamente a sequencia de movimentações para cada posição, de acordo com a posição relativa da posição atual e da saída (ex caso a saída esteja em baixo, down vai ser a primeira opção de movimentação, ao inves de up)
}

void print_route () {

}

void print_solved_labyrinth () {

}

int main () {

    const char *source[] = { //array de ponteiros, [ passado por função equivale a **source, mas na declaração não ] não sei to confusa em relação a isso
        "*********S",
        "*   *    *",
        "* * * ** *",
        "* *   *  *",
        "* *** ** *",
        "*   *    *",
        "*** * ** *",
        "*   *    *",
        "* *** ****",
        "E*********"
    };
    //int ROWS = 10, COLS = 10;

    //dinamicamente, precisa validar se todas as linhas possuem o mesmo tamanho depois
    int ROWS =  sizeof(source) / sizeof(source[0]);
    int COLS = strlen(source[0]);

    char enter_char, exit_char, char_wall;

    char **labyrinth;

    labyrinth = create_labyrinth(ROWS, COLS, source);
    if (labyrinth==NULL) {printf("nao foi possivel construir o labirinto"); return -1;}

    if (validate(ROWS, COLS, labyrinth, enter_char, exit_char, char_wall)!=1) {printf("labirinto invalido"); return -1;}


    return 0;
}