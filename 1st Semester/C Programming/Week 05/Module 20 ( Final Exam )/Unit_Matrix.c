#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int unit_matrix = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] != 1) {
                    unit_matrix = 0;
                    break;
                }
            } else {
                if(a[i][j] != 0) {
                    unit_matrix = 0;
                    break;
                }
            }
        }
    }

    if(unit_matrix == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}