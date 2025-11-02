#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = malloc(n * sizeof(int));
    if (!a) return 0;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 0; }
    }

    int peak_idx = -1;
    if (n == 1) {
        peak_idx = 0;
    } else {
        for (int i = 0; i < n; ++i) {
            int left_ok  = (i == 0)     ? 1 : (a[i] >= a[i-1]);
            int right_ok = (i == n - 1) ? 1 : (a[i] >= a[i+1]);
            if (left_ok && right_ok) { peak_idx = i; break; }
        }
    }

    if (peak_idx >= 0)
        printf("Peak found at index %d with value %d\n", peak_idx, a[peak_idx]);
    else
        printf("No peak found (unexpected)\n");

    free(a);
    return 0;
}