#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    long long int mul = (long long int)a * b;
    printf("%lld", mul);
    return 0;
}