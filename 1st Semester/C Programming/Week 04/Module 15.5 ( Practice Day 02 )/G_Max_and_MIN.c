#include <stdio.h>
#include <limits.h>

void minAndMax(int n) {
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x > max) {
            max = x;
        }
        if(x < min) {
            min = x;
        }
    }

    printf("%d %d\n", min, max);
}

int main() {
    int n;
    scanf("%d", &n);

    minAndMax(n);

    return 0;
}