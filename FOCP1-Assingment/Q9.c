#include <stdio.h>

int main(void) {
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 99) { index = i; break; } // linear search for first occurrence
    }

    if (index >= 0)
        printf("First occurrence of 99 is at index %d (position %d).\n", index, index + 1);
    else
        printf("99 not found in the array.\n");

    return 0;
}