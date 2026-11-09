Nível 1: Ponteiros básicos

Desafio 1.1: Troca
Escreva void troca(int *a, int *b) e teste no main com duas variáveis. Antes de rodar, escreva em um comentário o que você espera ver.

Desafio 1.2: Endereços
Declare int x = 10; int *p = &x; int **pp = &p;. Imprima x, &x, p, *p, &p, pp, *pp, **pp. Depois, sem rodar, diga qual valor é igual a qual. Em seguida altere x usando só pp.

Desafio 1.3: Min e max por ponteiro
Escreva void min_max(int *v, int n, int *min, int *max). A função devolve dois resultados pelos parâmetros. (É o mesmo mecanismo que o solver vai usar para devolver linha e coluna do E em find_position.)

Nível 2: Ponteiros e vetores

Desafio 2.1: Percorrer sem colchetes
Imprima um vetor de 5 inteiros usando só aritmética de ponteiros (*(p + i) e depois p++), sem v[i]. Depois descubra o que sizeof(v) e sizeof(p) imprimem e por quê são diferentes.

Desafio 2.2: Inverter no lugar
Escreva void inverte(int *v, int n) usando dois ponteiros, um começando no início e outro no fim, que se encontram no meio.

Desafio 2.3: Strings
Escreva int tamanho(char *s) (seu próprio strlen) e void copia(char *dest, char *src) (seu próprio strcpy), só com ponteiros.

Nível 3: malloc e free

Desafio 3.1: Vetor dinâmico
Leia n do teclado, aloque n inteiros com malloc, preencha com os quadrados (1, 4, 9...), imprima e libere. Sempre teste se o malloc retornou NULL.

Desafio 3.2: Retornar memória alocada
Escreva int *cria_sequencia(int n) que aloca, preenche com 0..n-1 e retorna o ponteiro. Quem libera? Onde? Escreva a resposta como comentário.

Desafio 3.3: Caçando bugs
Este código tem 3 erros de memória. Ache todos antes de compilar:

c
int *v = malloc(5 * sizeof(int));
for (int i = 0; i <= 5; i++) v[i] = i;
free(v);
printf("%d\n", v[2]);
free(v);

Depois rode com -fsanitize=address e confira se você achou os mesmos que a ferramenta.

Nível 4: calloc e realloc

Desafio 4.1: malloc vs calloc
Aloque 5 inteiros com malloc e imprima sem inicializar. Faça o mesmo com calloc. Explique a diferença com suas palavras e reescreva o calloc usando malloc + um loop (ou memset).

Desafio 4.2: Vetor que cresce
Leia números do teclado até digitar -1, sem saber quantos serão. Comece com capacidade 2 e dobre com realloc quando encher. No final, imprima os números e libere.
Dica de armadilha: não faça v = realloc(v, ...) direto. Se falhar, você perde o ponteiro original. Use um ponteiro temporário e teste.

Desafio 4.3: Remover do meio
Com o vetor do 4.2, faça remove_ultimo(...). Isso é exatamente o que remove_movement vai fazer no backtracking. Depois faça uma versão que encolhe com realloc quando o uso cai abaixo de 1/4 da capacidade.

Nível 5: Matrizes e ponteiro para ponteiro

Desafio 5.1: Matriz com int **
Aloque uma matriz linhas x colunas assim: primeiro um vetor de int * (as linhas), depois um calloc por linha. Preencha com i * colunas + j, imprima e libere na ordem certa (primeiro cada linha, depois o vetor de linhas). Pergunta: o que acontece se liberar na ordem inversa?

Desafio 5.2: Passando a matriz para função
Escreva void imprime(int **m, int l, int c) e void preenche(int **m, int l, int c, int valor). Depois escreva int **cria_matriz(int l, int c) e void libera_matriz(int **m, int l).

Desafio 5.3: Ponteiro para ponteiro como parâmetro de saída
Escreva void cria_vetor(int **out, int n) que aloca o vetor e coloca o endereço em *out. Chame com cria_vetor(&v, 5). Por que aqui precisa de int ** e não de int *? (Esse é o ponto que mais confunde, vale tentar explicar em voz alta.)

Desafio 5.4: Matriz de caracteres (lista de strings)
Leia n palavras e guarde em char **palavras, alocando cada uma com o tamanho exato. Imprima em ordem inversa e libere tudo.

Nível 6: Ponte para o labirinto

Aqui você junta tudo, e já usa o formato do desafio.

Desafio 6.1: Carregar o labirinto
Leia da entrada primeiro linhas colunas, depois as linhas do labirinto (*, espaço, E, S) para uma char ** alocada dinamicamente. Imprima de volta e libere. Cuidado: o espaço em branco faz o scanf("%s") falhar, então pense em fgets ou scanf(" %c").

Desafio 6.2: find_position
Escreva int find_position(char **lab, int l, int c, char alvo, int *lin, int *col) que procura 'E' (ou 'S') e devolve a posição pelos ponteiros, retornando 1 se achou e 0 se não.

Desafio 6.3: Matriz de estados
Crie uma int **estados do mesmo tamanho do labirinto, com -1 onde há parede e 0 no resto (você mencionou essa ideia). Imprima para conferir.

Desafio 6.4: Rota dinâmica
Crie uma estrutura de rota só com int *rota; int tam; int cap; usando variáveis soltas passadas por ponteiro (sem struct, já que você ainda não viu): void adiciona(int **rota, int *tam, int *cap, int mov) e void remove_ultimo(int *tam). Teste empilhando 20 movimentos e desempilhando 5.