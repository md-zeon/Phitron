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

    int secondary_diagonal = 1;

    if(row != col) {
        secondary_diagonal = 0;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if((i+j != row-1) && a[i][j] != 0) {
                secondary_diagonal = 0;
                break;
            }
        }
    }

    if(secondary_diagonal == 1) {
        printf("Secondary Diagonal");
    } else {
        printf("Not Secondary Diagonal");
    }

    return 0;
}