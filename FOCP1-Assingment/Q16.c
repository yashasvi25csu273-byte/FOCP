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

    printf("Array before insertion:");
    if (n == 0) printf(" (empty)\n");
    else {
        printf("\n");
        for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
        printf("\n");
        }

    int choice, val;
    printf("Insert at: 1) Front  2) Middle  3) End\nEnter choice (1-3): ");
    if (scanf("%d", &choice) != 1) { free(arr); return 0; }
    printf("Enter value to insert: ");
    if (scanf("%d", &val) != 1) { free(arr); return 0; }

    int new_n = n + 1;
    int *new_arr = realloc(arr, (size_t)new_n * sizeof(int));
    if (!new_arr) { free(arr); return 0; }
    arr = new_arr;

    if (choice == 1) { /* front */
        for (int i = new_n - 1; i > 0; --i) arr[i] = arr[i - 1];
        arr[0] = val;
    } else if (choice == 2) { /* middle: insert at index n/2 */
        int pos = n / 2;
        for (int i = new_n - 1; i > pos; --i) arr[i] = arr[i - 1];
        arr[pos] = val;
        } else { /* end or invalid -> append at end */
        arr[new_n - 1] = val;
    }

    printf("Array after insertion:\n");
    for (int i = 0; i < new_n; ++i) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}