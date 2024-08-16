#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int firstDigit = n / 1000;

    if(firstDigit & 1) {
        printf("ODD\n");
    } else {
        printf("EVEN\n");
    }

    return 0;
}