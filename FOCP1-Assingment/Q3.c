#include <stdio.h>

/* add two integers using only bitwise operators */
int bitwise_add(int x, int y) {
    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = (unsigned)carry << 1;
    }
    return x;
}

/* subtract b from a without using '-' by adding two's complement of b */
int bitwise_subtract(int a, int b) {
    int negb = bitwise_add(~b, 1); /* two's complement of b */
    return bitwise_add(a, negb);
}

int main(void) {
    int a, b;
    printf("Enter two integers (a b): ");
    if (scanf("%d %d", &a, &b) != 2) return 0;

    int result = bitwise_subtract(a, b);
    printf("%d - %d = %d\n", a, b, result);
    return 0;
}