#include <stdio.h>
#include <stdlib.h>

/*Nível 4: calloc e realloc

Desafio 4.1: malloc vs calloc
Aloque 5 inteiros com malloc e imprima sem inicializar. Faça o mesmo com calloc. Explique a diferença com suas palavras e reescreva o calloc usando malloc + um loop (ou memset).

Desafio 4.2: Vetor que cresce
Leia números do teclado até digitar -1, sem saber quantos serão. Comece com capacidade 2 e dobre com realloc quando encher. No final, imprima os números e libere.
Dica de armadilha: não faça v = realloc(v, ...) direto. Se falhar, você perde o ponteiro original. Use um ponteiro temporário e teste.

Desafio 4.3: Remover do meio
Com o vetor do 4.2, faça remove_ultimo(...). Isso é exatamente o que remove_movement vai fazer no backtracking. Depois faça uma versão que encolhe com realloc quando o uso cai abaixo de 1/4 da capacidade.
*/

void alocar_malloc () {

}

void alocar_calloc () {

}

int main () {
    return 0;
}