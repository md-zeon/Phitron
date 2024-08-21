#include <stdio.h>

void sum(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
}

int main() {
    sum();
    sum();    

    return 0;
}