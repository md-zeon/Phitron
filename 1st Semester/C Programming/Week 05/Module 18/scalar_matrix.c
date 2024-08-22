#include <stdio.h>

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int a[row][col];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int scalar_matrix = 1;

    if(row != col) {
        scalar_matrix = 0;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == j) {
                if(a[i][j] != a[0][0]) {
                    scalar_matrix = 0;
                    break;
                }
            } else if(a[i][j] != 0) {
                scalar_matrix = 0;
                break;
            }
        }
    }

    if(scalar_matrix == 1) {
        printf("Scalar Matrix");
    } else {
        printf("Not Scalar Matrix");
    }

    return 0;
}