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

    int zero_matrix = 1;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(a[i][j] != 0) {
                zero_matrix = 0;
                break;
            }
        }
    }

    if(zero_matrix == 1) {
        printf("Zero Matrix");
    } else {
        printf("Not Zero Matrix");
    }







    return 0;
}