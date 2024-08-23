#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    long long int s, a, b, c;

    while(t--) {
        scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
        printf("%lld\n", s - (a + b + c));
    }

    return 0;
}