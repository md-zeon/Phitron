#include <stdio.h>

// global scope
int x = 10;

void fun(void) {
    int s = 100;
    printf("Address of s in fun = %p\n", &s);
}

int main() {
    int s = 200;
    printf("Address of s in Main = %p\n", &s);
    fun();

    return 0;
}