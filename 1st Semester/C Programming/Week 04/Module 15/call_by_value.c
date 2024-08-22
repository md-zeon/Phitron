#include <stdio.h>

void func(int x) {
    printf("func e x er address - %p\n", &x);
}

int main() {

    int x = 10;
    printf("main e x er address - %p\n", &x);
    func(x);
    func(x + 10);

    return 0;
}