#include <stdio.h>

int main() {
    int n, s, k;
    scanf("%d", &n);
    s = n-1;
    k = 1;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= s; j++) {
            printf(" ");
        }
        for(int j = 1; j <= k; j++) {
            printf("*");
        }
        s--;
        k += 2;
        printf("\n");
    }

    printf("\n\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            printf(" ");
        }

        for(int j = 0; j < 2*(n-i)-1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}