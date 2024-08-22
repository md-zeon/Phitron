#include <stdio.h>

void func(int *p) {
    printf("func e x er address - %p\n", p);
    printf("func e x er value - %d\n", *p);
    *p = 20;
    printf("func e x er value - %d\n", *p);
}

int main() {

    int x = 10;

    printf("main e x er address - %p\n", &x);
    printf("main e x er value - %d\n", x);
    func(&x);
    printf("main e x er value - %d\n", x);

    return 0;
}