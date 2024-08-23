#include <stdio.h>

int main() {

    float x, p;

    scanf("%f %f", &x, &p);

    float original_price = (p / (1.0 - (x / 100.00)));

    printf("%0.2f\n", original_price);

    return 0;
}