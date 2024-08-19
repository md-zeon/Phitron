#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n\n");
    int s = n, k = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= s; j++) {
            printf("  ");
        }
        for(int j = 1; j <= k; j++) {
            printf(" *");
        }
        k++;
        s--;
        printf("\n");
    }

    return 0;
}