#include <stdio.h>


int main() {
    int a = 20, b = 3;
    int sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);

    int sub = a - b;
    printf("%d - %d = %d\n", a, b, sub);

    int mul = a * b;
    printf("%d * %d = %d\n", a, b, mul);

    int div = a / b;
    printf("%d / %d = %d\n", a, b, div);

    int mod = a % b;
    printf("%d %% %d = %d\n", a, b, mod);

    return 0;
}