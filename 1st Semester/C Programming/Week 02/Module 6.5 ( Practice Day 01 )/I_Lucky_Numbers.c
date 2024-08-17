#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int firstDigit = n / 10;
    int lastDigit = n % 10;

    if(n % 10 == 0) {
        printf("YES\n");
    } else if(firstDigit % lastDigit == 0 || lastDigit % firstDigit == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }


    return 0;
}