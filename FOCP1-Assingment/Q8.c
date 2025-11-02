#include <stdio.h>

int main(void) {
    int n;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("No terms\n");
        return 0;
    }

    long long a = 0, b = 1;
    printf("%lld", a);
    if (n > 1) printf(", %lld", b);

    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        printf(", %lld", c);
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}