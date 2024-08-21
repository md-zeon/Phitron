#include <stdio.h>

void sum(int x, int y) {

    printf("%d\n", x + y);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    sum(a, b);
    

    return 0;
}