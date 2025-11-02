#include <stdio.h>

int main(void) {
    double x, y;
    printf("Enter coordinates x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 0;

    if (x == 0.0 && y == 0.0) {
        printf("Point is at the Origin\n");
    } else if (x == 0.0) {
        printf("Point lies on the Y axis\n");
    } else if (y == 0.0) {
        printf("Point lies on the X axis\n");
    } else if (x > 0.0 && y > 0.0) {
        printf("Quadrant I\n");
    } else if (x < 0.0 && y > 0.0) {
        printf("Quadrant II\n");
    } else if (x < 0.0 && y < 0.0) {
        printf("Quadrant III\n");
    } else { /* x > 0 && y < 0 */
        printf("Quadrant IV\n");
    }

    return 0;
}

