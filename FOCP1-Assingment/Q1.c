#include <stdio.h>

/* simple integer power */
int ipow(int base, int exp) {
    int r = 1;
    for (int i = 0; i < exp; ++i) r *= base;
    return r;
}

int main(void) {
    long long num;
    if (printf("Enter a non-negative integer: "), fflush(stdout), scanf("%lld", &num) != 1) return 0;

    if (num < 0) {
        printf("Negative numbers are not Armstrong numbers\n");
        return 0;
    }

    long long tmp = num;
    int digits = 0;
    if (tmp == 0) digits = 1;
    while (tmp > 0) { digits++; tmp /= 10; }

    tmp = num;
    long long sum = 0;
     while (tmp > 0) {
        int d = tmp % 10;
        sum += ipow(d, digits);
        tmp /= 10;
    }

    if (sum == num)
        printf("%lld is an Armstrong number\n", num);
    else
        printf("%lld is not an Armstrong number\n", num);

        return 0;}
        