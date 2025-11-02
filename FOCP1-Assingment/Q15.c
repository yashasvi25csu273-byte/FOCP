#include<stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 0;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) { free(arr); return 0; }
    }

    if (n > 1) {
        int last = arr[n - 1];
        for (int i = n - 1; i > 0; --i) arr[i] = arr[i - 1];
        arr[0] = last;
    }

    printf("Rotated array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d%s", arr[i], (i + 1 == n) ? "\n" : " ");
    }

    free(arr);
    return 0;
}