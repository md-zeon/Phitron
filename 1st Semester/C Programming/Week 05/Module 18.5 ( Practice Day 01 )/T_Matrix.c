#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n][n];
    int main_sum = 0, secondary_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i == j) {
                main_sum += a[i][j];
            }
            if (i + j == n - 1) {
                secondary_sum += a[i][j];
            }
        }
    }

    printf("%d\n", abs(main_sum - secondary_sum));


    return 0;
}