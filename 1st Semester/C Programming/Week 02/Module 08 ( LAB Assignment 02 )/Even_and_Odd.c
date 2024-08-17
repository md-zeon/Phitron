#include <stdio.h>

int main() {
    int num, v, evenSum = 0, oddSum = 0;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        scanf("%d", &v);
        if(v % 2 == 0) {
            evenSum += v;
        } else {
            oddSum += v;
        }
    }

    printf("%d %d\n", evenSum, oddSum);

    return 0;
}