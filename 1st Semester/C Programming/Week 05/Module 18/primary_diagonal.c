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

    int primary_diagonal = 1;

    if(row != col) {
        primary_diagonal = 0;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i != j && a[i][j] != 0) {
                primary_diagonal = 0;
                break;
            }
        }
    }

    if(primary_diagonal == 1) {
        printf("Primary Diagonal");
    } else {
        printf("Not Primary Diagonal");
    }

    return 0;
}