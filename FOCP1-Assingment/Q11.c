#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of scores: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *scores = malloc((size_t)n * sizeof(int));
    if (!scores) return 0;

    printf("Enter %d scores:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &scores[i]) != 1) { free(scores); return 0; }
    }

    int *even = malloc((size_t)n * sizeof(int));
    int *odd  = malloc((size_t)n * sizeof(int));
    if (!even || !odd) { free(scores); free(even); free(odd); return 0; }

    int ec = 0, oc = 0;
    for (int i = 0; i < n; ++i) {
        if (scores[i] % 2 == 0) even[ec++] = scores[i];
        else                    odd[oc++]  = scores[i];
    }

    printf("Even count: %d\n", ec);
    if (ec) {
        printf("Even array: ");
        for (int i = 0; i < ec; ++i) printf("%d ", even[i]);
        printf("\n");
    }

    printf("Odd count: %d\n", oc);
    if (oc) {
        printf("Odd array: ");
        for (int i = 0; i < oc; ++i) printf("%d ", odd[i]);
        printf("\n");
    }

    free(scores);
    free(even);
    free(odd);
    return 0;
}
