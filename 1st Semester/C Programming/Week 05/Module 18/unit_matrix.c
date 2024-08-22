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

    int unit_matrix = 1;

    if(row != col) {
        unit_matrix = 0;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == j) {
                if(a[i][j] != 1) {
                    unit_matrix = 0;
                    break;
                }
            } else if(a[i][j] != 0) {
                unit_matrix = 0;
                break;
            }
        }
    }

    if(unit_matrix == 1) {
        printf("Unit Matrix");
    } else {
        printf("Not Unit Matrix");
    }

    return 0;
}