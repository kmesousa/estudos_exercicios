#include <stdio.h>
#include <conio.h> // Necessário para getch() no Windows

int main() {
    char tecla;

    printf("Pressione qualquer tecla...\n");
    tecla = getch(); // Lê o caractere sem mostrar na tela e sem apertar Enter

    printf("Voce pressionou a tecla de codigo ASCII: %d\n", tecla);
    return 0;
}