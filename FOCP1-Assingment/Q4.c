#include <stdio.h>

/* swap using pointer (temporary inside function) */
void swap_ptr(int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
}

int main(void) {
    int a, b;
    printf("Enter two integers (a b): ");
    if (scanf("%d %d", &a, &b) != 2) return 0;

    int x, y;

    /* 1) Temporary variable */
    x = a; y = b;
    printf("Method 1 (temp)- before: %d %d\n", x, y);
     {
        int temp = x;
        x = y;
        y = temp;
    }
    printf(" - after : %d %d\n\n", x, y);

    /* 2) Arithmetic (no extra variable) */
    x = a; y = b;
    printf("Method 2 (arith)   - before: %d %d\n", x, y);
    /* Note: may overflow for large values */
    x = x + y;
    y = x - y;
    x = x - y;
    printf(" - after : %d %d\n\n", x, y);

    /* 3) Bitwise XOR (no extra variable) */
    x = a; y = b;
    printf("Method 3 (XOR) - before: %d %d\n", x, y);
    x ^= y;
    y ^= x;
    x ^= y;
    printf(" - after : %d %d\n\n", x, y);

    /* 4) Pointer manipulation (using a function) */
    x = a; y = b;
    printf("Method 4 (pointer) - before: %d %d\n", x, y);
    swap_ptr(&x, &y);
    printf("- after : %d %d\n", x, y);

    return 0;
}