#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_binary_string(const char *s) {
    if (*s == '\0') return 0;
    for (; *s; ++s) if (*s != '0' && *s != '1') return 0;
    return 1;
}

int main(void) {
    int choice;
    while (1) {
        printf("\nChoose conversion:\n");
        printf("1. Binary -> Decimal\n");
        printf("2. Decimal -> Binary\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 1) {
            char bin[129];
            printf("Enter binary (up to 128 bits): ");
            if (scanf("%128s", bin) != 1) continue;
            if (!is_binary_string(bin)) {
                printf("Invalid binary input.\n");
                continue;
            }
            unsigned long long dec = 0;
            for (size_t i = 0; bin[i]; ++i) {
                dec = dec * 2 + (bin[i] - '0');
            }
            printf("Decimal: %llu\n", dec);
        }
        else if (choice == 2) {
            unsigned long long dec;
            printf("Enter non-negative decimal: ");
            if (scanf("%llu", &dec) != 1) continue;
            if (dec == 0) {
                printf("Binary: 0\n");
                continue;
            }
            char buf[129];
            int idx = 0;
            while (dec > 0 && idx < (int)sizeof(buf)-1) {
                buf[idx++] = (dec & 1) ? '1' : '0';
                dec >>= 1;
                  }
            buf[idx] = '\0';
            // reverse
            for (int i = 0, j = idx-1; i < j; ++i, --j) {
                char t = buf[i]; buf[i] = buf[j]; buf[j] = t;
            }
            printf("Binary: %s\n", buf);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}