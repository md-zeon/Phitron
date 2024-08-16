#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        int lastDigit;
        do {
            lastDigit = n % 10;
            printf("%d ", lastDigit);
            n = n / 10;
        } while(n != 0);
        printf("\n");
    }

    return 0;
}