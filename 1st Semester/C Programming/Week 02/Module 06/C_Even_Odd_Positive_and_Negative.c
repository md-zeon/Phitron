#include <stdio.h>

int main() {
    int n, even, odd, positive, negative, num;

    even = odd = positive = negative = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num % 2 == 0) {
            even++;
        } else {
            odd++;
        }

        if(num > 0) {
            positive++;
        } else if(num < 0) {
            negative++;
        }
    }

    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);

    return 0;
}