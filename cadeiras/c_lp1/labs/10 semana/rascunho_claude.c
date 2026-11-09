#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 RASCUNHO - solver de labirinto (backtracking iterativo, 8 direções, array de visitadas)

 DECISÕES SOBRE OS DADOS
 - labyrinth: char **  (LINES linhas, COLS colunas), acessado como labyrinth[linha][coluna]
 - posição:   um único int, chamado aqui de "cell"
                 cell   = linha * COLS + coluna
                 linha  = cell / COLS
                 coluna = cell % COLS
              assim não precisa de struct nem de array de pares
 - route:     int *  com capacidade LINES * COLS
              (com o array de visitadas, cada casa entra no máximo 1 vez na rota,
               então dá para fazer um malloc só; realloc fica opcional, veja add_to_route)
 - visited:   char * de tamanho LINES * COLS, zerado com calloc, indexado pela mesma cell
 - direções:  índice 0..7, sentido horário começando por cima

                 7  0  1
                 6  x  2
                 5  4  3

 RETORNOS (convenção)
 - funções que respondem "deu certo?" devolvem 1 (sim) ou 0 (não)
*/

// variação de linha e de coluna para cada uma das 8 direções (mesmo índice nos dois)
const int DR[8] = { -1, -1,  0,  1,  1,  1,  0, -1 };
const int DC[8] = {  0,  1,  1,  1,  0, -1, -1, -1 };


/* ------------------------------------------------------------------ */
/* CRIAÇÃO E LIBERAÇÃO DO LABIRINTO                                    */
/* ------------------------------------------------------------------ */

char **create_labyrinth(int LINES, int COLS, const char *source[]) {
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
    return NULL;
}

void free_labyrinth(int LINES, char **labyrinth) {
    // 1. para cada linha i: free(labyrinth[i])
    // 2. free(labyrinth)
}


/* ------------------------------------------------------------------ */
/* VALIDAÇÃO E BUSCA DE ENTRADA / SAÍDA                                */
/* ------------------------------------------------------------------ */

int validate(int LINES, int COLS, char **labyrinth, char enter_char, char exit_char, char wall) {
    /* confere se o labirinto é utilizável (o tamanho das linhas já foi conferido em create_labyrinth) */

    int count_enter = 0, count_exit = 0;

    // 1. percorrer toda a matriz
    // 2. para cada char:
    //      - se for enter_char: count_enter++
    //      - se for exit_char:  count_exit++
    //      - se não for wall, ' ', enter_char nem exit_char: caractere inválido -> retornar 0
    // 3. se count_enter != 1 ou count_exit != 1 -> retornar 0
    // 4. retornar 1
    return 0;
}

int find_position(char obj, int *position, int LINES, int COLS, char **labyrinth) {
    /* procura a primeira ocorrência de obj; quem chama cria o int position[2] e passa aqui
       preenche position[0] = linha, position[1] = coluna
       retorna 1 se achou, 0 se não achou (comece valid = 0) */

    int valid = 0;

    // 1. percorrer a matriz linha por linha
    // 2. ao encontrar labyrinth[i][j] == obj:
    //      position[0] = i; position[1] = j; valid = 1; parar a busca
    return valid;
}


/* ------------------------------------------------------------------ */
/* AUXILIARES DE MOVIMENTO                                             */
/* ------------------------------------------------------------------ */

int is_valid_cell(int row, int col, int LINES, int COLS, char **labyrinth, char *visited, char wall) {
    /* responde: posso entrar nessa casa candidata? (row e col podem estar fora do labirinto) */

    // 1. se row < 0 ou row >= LINES ou col < 0 ou col >= COLS -> retornar 0
    //    (essa checagem vem primeiro, antes de acessar a matriz)
    // 2. se labyrinth[row][col] == wall -> retornar 0
    // 3. se visited[row * COLS + col] != 0 -> retornar 0
    // 4. retornar 1
    return 0;
}

int direction_between(int from, int to, int COLS) {
    /* descobre qual direção (0..7) leva da casa "from" até a casa "to"
       (as duas em formato cell); retorna -1 se não forem vizinhas */

    // 1. dr = (to / COLS) - (from / COLS)
    //    dc = (to % COLS) - (from % COLS)
    // 2. para d de 0 a 7: se DR[d] == dr e DC[d] == dc -> retornar d
    // 3. retornar -1
    return -1;
}


/* ------------------------------------------------------------------ */
/* PILHA DA ROTA                                                       */
/* ------------------------------------------------------------------ */

void add_to_route(int *route, int *route_len, int cell) {
    /* push: coloca a casa no fim da rota */

    // 1. route[*route_len] = cell
    // 2. (*route_len)++
    //
    // opcional (para praticar realloc): receber int **route e int *capacity;
    // se *route_len == *capacity, dobrar a capacidade com realloc, checar NULL e
    // atualizar *route (por isso precisa do ponteiro duplo)
}

int remove_from_route(int *route, int *route_len) {
    /* pop: tira a última casa da rota e devolve ela */

    // 1. (*route_len)--
    // 2. retornar route[*route_len]   (a posição que acabou de sair)
    return -1;
}


/* ------------------------------------------------------------------ */
/* IMPRESSÃO                                                           */
/* ------------------------------------------------------------------ */

void print_route(int *route, int route_len, int COLS) {
    // 1. imprimir o total de passos (route_len)
    // 2. para cada i de 0 a route_len - 1:
    //      imprimir linha = route[i] / COLS e coluna = route[i] % COLS
    //      (decidir se imprime 0-based ou 1-based; o enunciado não diz)
}

void print_labyrinth_with_route(int LINES, int COLS, char **labyrinth, int *route, int route_len, char enter_char, char exit_char) {
    /* imprime o labirinto com o caminho marcado, SEM alterar a matriz original */

    char *on_route; // array de flags LINES * COLS, calloc

    // 1. alocar on_route com calloc e checar NULL
    // 2. para cada casa da rota: on_route[route[i]] = 1
    // 3. para cada linha i e coluna j:
    //      - se on_route[i * COLS + j] e o char NÃO é enter_char/exit_char: imprimir '-'
    //      - senão: imprimir labyrinth[i][j]
    //    (quebra de linha no fim de cada linha da matriz)
    // 4. free(on_route)
}


/* ------------------------------------------------------------------ */
/* SOLVER                                                              */
/* ------------------------------------------------------------------ */

int solve_labyrinth(int LINES, int COLS, char **labyrinth, char enter_char, char exit_char, char wall) {
    /* o parâmetro "paths" foi removido: tudo que não é parede é caminhável
       retorna 1 se achou caminho, 0 se não existe, -1 se deu erro (labirinto inválido / sem memória) */

    int enter_pos[2], exit_pos[2];       // {linha, coluna}
    int enter_cell, exit_cell;           // mesmas posições, no formato cell
    int *route;                          // pilha de cells
    int route_len = 0;
    char *visited;
    int cur_cell, cur_row, cur_col;
    int new_row, new_col;
    int next_dir = 0;                    // próxima direção a testar na casa atual
    int d, moved, removed, top;
    int found = 0;

    // 1. validar: se validate(...) devolver 0 -> retornar -1
    // 2. find_position para a entrada e para a saída (preenche enter_pos e exit_pos)
    //    converter cada uma para cell: linha * COLS + coluna
    // 3. alocar route (LINES * COLS ints) e visited (calloc, LINES * COLS chars)
    //    checar NULL (se um falhar, liberar o outro antes de retornar -1)
    // 4. começar: add_to_route(enter_cell), visited[enter_cell] = 1, next_dir = 0
    //
    // 5. enquanto route_len > 0:
    //      5.1 cur_cell = route[route_len - 1]
    //          se cur_cell == exit_cell: found = 1; sair do laço
    //      5.2 cur_row = cur_cell / COLS; cur_col = cur_cell % COLS
    //      5.3 moved = 0
    //          para d de next_dir até 7:
    //              new_row = cur_row + DR[d]; new_col = cur_col + DC[d]
    //              se is_valid_cell(new_row, new_col, ...) -> moved = 1; sair do for
    //      5.4 se moved:
    //              add_to_route(new_row * COLS + new_col)
    //              visited[new_row * COLS + new_col] = 1   (nunca é desmarcada, nem no retorno)
    //              next_dir = 0                             (casa nova: testa as 8 desde o começo)
    //      5.5 senão (beco sem saída, nenhuma direção serviu):
    //              removed = remove_from_route(...)
    //              se route_len == 0: sair do laço (voltou da entrada, não há solução)
    //              top = route[route_len - 1]
    //              next_dir = direction_between(top, removed, COLS) + 1
    //                         (retoma na direção seguinte à que levou ao beco)
    //
    // 6. se found:
    //        print_route(route, route_len, COLS)
    //        print_labyrinth_with_route(...)
    //    senão: imprimir que não há caminho
    // 7. free(route) e free(visited)  (todos os caminhos de saída depois do passo 3 precisam disso)
    // 8. retornar found
    return found;
}


/* ------------------------------------------------------------------ */
/* OPCIONAIS                                                           */
/* ------------------------------------------------------------------ */

int are_adjacent(int a, int b, int COLS) {
    // retorna 1 se as duas cells são vizinhas nas 8 direções (pode usar direction_between != -1)
    return 0;
}

void shorten_route(int *route, int *route_len, int COLS) {
    /* tira atalhos da rota já pronta; não garante o caminho mínimo, só melhora */

    // 1. i = 0
    // 2. enquanto i < *route_len - 1:
    //      2.1 procurar o MAIOR j > i + 1 tal que are_adjacent(route[i], route[j], COLS)
    //      2.2 se achou j: remover as posições i+1 .. j-1
    //          (deslocar route[j..fim] para route[i+1..], e diminuir *route_len)
    //      2.3 i++
}


int main () {
    // labirinto do enunciado, com a última linha completada para ter 10 colunas
    const char *source[] = {
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
    int LINES = 10, COLS = 10;
    char **labyrinth;
    int result;

    // 1. labyrinth = create_labyrinth(LINES, COLS, source); se NULL -> mensagem e return 1
    // 2. result = solve_labyrinth(LINES, COLS, labyrinth, 'E', 'S', '*')
    // 3. mensagem conforme result (1 achou, 0 sem caminho, -1 erro)
    // 4. free_labyrinth(LINES, labyrinth)
    return 0;
}