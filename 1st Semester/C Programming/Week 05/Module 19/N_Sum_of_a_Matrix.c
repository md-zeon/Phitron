#include <stdio.h>

void matrix_sum(int a[][100], int b[][100], int n, int m, int i, int j) {
    if (i == n) {
        return;
    }
    if(j == m) {
        printf("\n");
        matrix_sum(a, b, n, m, i+1, 0);
    } else {
        printf("%d ", a[i][j] + b[i][j]);
        matrix_sum(a,b,n,m,i, j+1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100][100];
    int b[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    matrix_sum(a, b, n, m, 0, 0);

    return 0;
}