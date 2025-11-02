#include <stdio.h>
#include <stdlib.h>

int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid count or no input.\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof *arr);
    if (!arr) { perror("malloc"); return 0; }

    printf("Enter %d integers (separated by spaces or newlines):\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &arr[i]) != 1) {
            printf("Input ended prematurely.\n");
            free(arr);
            return 0;
        }
    }
     int count = 0;
    for (int i = 0; i < n; ++i) {
        if (is_prime(arr[i])) ++count;
    }

    printf("Number of prime numbers in the array: %d\n", count);
    free(arr);
    return 0;
}
