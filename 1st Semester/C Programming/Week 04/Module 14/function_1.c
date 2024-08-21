#include <stdio.h>

int sum(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    printf("%d\n", sum(10, 20));
    printf("%d\n", sum(20, 30));
    printf("%d\n", sum(100, 200));

    return 0;
}