#include <stdio.h>

long long int factorial(n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%lld", factorial(n));

    return 0;
}