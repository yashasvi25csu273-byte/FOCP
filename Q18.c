#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (printf("Enter array size: "), scanf("%d", &n) != 1 || n <= 0) return 0;

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (!arr) return 0;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &arr[i]) != 1) { free(arr); return 0; }
    }

    int any = 0;
    for (int i = 0; i < n; ++i) {
        int seen_before = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j] == arr[i]) { seen_before = 1; break; }
        }
        if (seen_before) continue;

        int has_later = 0;
        for (int k = i + 1; k < n; ++k) {
            if (arr[k] == arr[i]) { has_later = 1; break; }
        }
        if (has_later) {
            if (any) printf(" ");
            printf("%lld", arr[i]);
            any = 1;
        }
    }

    if (!any) printf("-1");
    printf("\n");

    free(arr);
    return 0;
} 