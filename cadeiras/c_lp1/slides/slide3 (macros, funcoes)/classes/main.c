#include <stdio.h>

void teste() {
    int a = 10;
    static int sa = 10;
    a += 5;
    sa += 5;
    printf("a = %d, sa = %d\n", a, sa);
}

int main () {
    int i;
    for (i = 0; i <= 3 ; ++i)
        teste();
    return 0;
}