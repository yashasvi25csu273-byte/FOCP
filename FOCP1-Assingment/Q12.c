

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = malloc((size_t)n * sizeof(int));
    if (!arr) return 0;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) { free(arr); return 0; }
    }

    int max = arr[0], min = arr[0];
    int max_idx = 0, min_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) { max = arr[i]; max_idx = i; }
        if (arr[i] < min) { min = arr[i]; min_idx = i; }
    }

    printf("Maximum value: %d (index %d)\n", max, max_idx); // 0-based index
    printf("Minimum value: %d (index %d)\n", min, min_idx);

    free(arr);
    return 0;
}
