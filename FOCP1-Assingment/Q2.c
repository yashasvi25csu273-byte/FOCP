#include <stdio.h>
#include <stdlib.h>

/* Iterative Euclidean algorithm */
int hcf_iterative(int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int hcf_recursive(int a, int b) {
    a = abs(a); b = abs(b);
    if (b == 0) return a;
    return hcf_recursive(b, a % b);
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 0;

    int h1 = hcf_iterative(x, y);
    int h2 = hcf_recursive(x, y);

    printf("HCF (iterative) of %d and %d is %d\n", x, y, h1);
    printf("HCF (recursive) of %d and %d is %d\n", x, y, h2);
    return 0;
}

