#include <stdio.h>

int main() {
    int n, x, max;
    scanf("%d", &n);
    scanf("%d", &x);
    max = x;
    for(int i = 1; i < n; i++) {
        scanf("%d", &x);
        if(x > max) {
            max = x;
        }
    }

    printf("%d\n", max);

    return 0;
}