#include <stdio.h>

int main() {
    long long int eyes, mouths, bodies;
    long long int maximum = 0;
    scanf("%lld %lld %lld", &eyes, &mouths, &bodies);

    long long int type1 = (eyes < mouths) ? (eyes < bodies ? eyes : bodies) : (mouths < bodies ? mouths : bodies);
    eyes -= type1;
    mouths -= type1;
    bodies -= type1;
    maximum += type1;

    long long int type2 = (eyes / 2 < bodies) ? (eyes / 2) : bodies;
    maximum += type2;

    printf("%lld\n", maximum);

    return 0;
}
