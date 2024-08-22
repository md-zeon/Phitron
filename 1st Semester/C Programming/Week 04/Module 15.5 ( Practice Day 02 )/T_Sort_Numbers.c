#include <stdio.h>


void sort(int a, int b, int c) {
    int x, y, z;
    x = a < b && a < c ? a : b < c ? b : c;
    z = a > b && a > c ? a : b > c ? b : c;
    y = a + b + c - x - z;

    printf("%d\n%d\n%d\n", x, y, z);
    printf("\n");
    printf("%d\n%d\n%d\n", a, b, c);
}


int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    sort(a, b, c);
    return 0;
}