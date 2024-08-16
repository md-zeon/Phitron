#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if(n % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }

    // if(n & 1) {
    //     printf("Odd\n");
    // } else {
    //     printf("Even\n");
    // }

    return 0;
}