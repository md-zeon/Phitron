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

    int secondary_unit_matrix = 1;

    if(row != col) {
        secondary_unit_matrix = 0;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i+j == row-1) {
                if(a[i][j] != 1) {
                    secondary_unit_matrix = 0;
                    break;
                }
            } else if(a[i][j] != 0) {
                secondary_unit_matrix = 0;
                break;
            }
        }
    }

    if(secondary_unit_matrix == 1) {
        printf("Secondary Unit Matrix");
    } else {
        printf("Not Secondary Unit Matrix");
    }

    return 0;
}