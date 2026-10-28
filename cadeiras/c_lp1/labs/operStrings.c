#include <stdio.h>
#include <stdlib.h>

char* ler_string_dinamica() {
    size_t capacidade = 16; // Começa com um bloco pequeno
    size_t tamanho = 0;
    char *buffer = malloc(capacidade * sizeof(char));

    if (!buffer) return NULL;

    int c;
    // Lê caractere por caractere até o Enter (\n) ou fim do arquivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF) {
        // Se faltar espaço para o caractere atual + o '\0'
        if (tamanho + 1 >= capacidade) {
            capacidade *= 2; // Dobra a capacidade do bloco
            char *temp = realloc(buffer, capacidade * sizeof(char));
            if (!temp) {
                free(buffer);
                return NULL; // Erro de memória
            }
            buffer = temp;
        }
        buffer[tamanho++] = c;
    }

    buffer[tamanho] = '\0'; // Finaliza a string de forma segura
    return buffer;
}

int lerString_Main() {
    printf("Digite qualquer texto: ");
    char *texto = ler_string_dinamica();

    if (texto) {
        printf("Texto capturado: %s\n", texto);
        free(texto);
    }
    return 0;
}
