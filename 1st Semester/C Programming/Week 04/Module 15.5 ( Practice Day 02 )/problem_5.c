#include <stdio.h>

void swap_it(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap_it(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}