#include <stdio.h>

int main() {

    int x = 10;

    int *ptr = &x;
    printf("x er address - %p\n", &x);
    printf("ptr er value - %p\n", ptr);
    printf("ptr er address - %p\n", &ptr);
    printf("x er value - %d\n", x);
    printf("x er value - %d\n", *ptr);

    return 0;
}