#include <stdio.h>

int main(void) {
    int rows = 5;
    for (int r = 1; r <= rows; r++) {
        for (int i = 0; i < r; i++) printf("%d", (i % 2) ? 1 : 0);
        printf(" ");
        for (int i = 0; i < r; i++) printf("%d", (i % 2) ? 1 : 0);
        printf("\n");
    }
    return 0;
}