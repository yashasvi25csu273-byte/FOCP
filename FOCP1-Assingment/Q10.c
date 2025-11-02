#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    /* consume leftover newline after scanf */
    int ch = getchar();
    if (ch != '\n' && ch != EOF) ungetc(ch, stdin);

    char (*names)[101] = malloc((size_t)n * sizeof *names);
    if (!names) return 0;
    int *marks = malloc((size_t)n * sizeof *marks);
    if (!marks) { free(names); return 0; }

    for (int i = 0; i < n; ++i) {
        printf("Enter name for student %d: ", i + 1);
        if (!fgets(names[i], sizeof names[i], stdin)) { free(names); free(marks); return 0; }
        /* remove trailing newline */
        names[i][strcspn(names[i], "\r\n")] = '\0';
         printf("Enter mark for student %d: ", i + 1);
        if (scanf("%d", &marks[i]) != 1) { free(names); free(marks); return 0; }
        /* consume newline after scanf */
        ch = getchar();
        if (ch != '\n' && ch != EOF) ungetc(ch, stdin);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) if (marks[i] == 99) ++count;

    if (count == 0) {
        printf("No student scored 99.\n");
    } else {
        printf("Number of students who scored 99: %d\n", count);
        printf("Students who scored 99 (position : name):\n");
        for (int i = 0; i < n; ++i) {
            if (marks[i] == 99) printf("%d : %s\n", i + 1, names[i]);
        }
    }

    free(names);
    free(marks);
        return 0;}