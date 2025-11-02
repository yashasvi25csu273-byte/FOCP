#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter initial array size: ");
    if (scanf("%d", &n) != 1 || n < 0) return 0;

    int *arr = NULL;
    if (n > 0) {
        arr = malloc((size_t)n * sizeof(int));
        if (!arr) return 0;
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; ++i) {
            if (scanf("%d", &arr[i]) != 1) { free(arr); return 0; }
        }
    }
     printf("Array before deletion:");
    if (n == 0) {
        printf(" (empty)\n");
    } else {
        printf("\n");
        for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
        printf("\n");
    }

    if (n == 0) { free(arr); return 0; }

    int choice;
    printf("Delete from: 1) Front  2) Middle  3) End\nEnter choice (1-3): ");
    if (scanf("%d", &choice) != 1) { free(arr); return 0; }

    int pos;
    if (choice == 1) {
        pos = 0;
    } else if (choice == 2) {
        pos = n / 2; /* middle index (0-based) */
    } else {
        pos = n - 1;
    }

    /* shift left elements after pos */
    for (int i = pos; i < n - 1; ++i) arr[i] = arr[i + 1];
    --n;

    /* shrink array (optional) */
    if (n > 0) {
         int *tmp = realloc(arr, (size_t)n * sizeof(int));
        if (tmp) arr = tmp;
    } else {
        free(arr);
        arr = NULL;
    }

    printf("Array after deletion:");
    if (n == 0) {
        printf(" (empty)\n");
    } else {
        printf("\n");
        for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    return 0;}