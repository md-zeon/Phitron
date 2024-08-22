#include <stdio.h>

void print(int n) {
    for(int i = 1; i <= n; i++) {
        (i == n) ? printf("%d", i) : printf("%d ", i);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    print(n);

    return 0;
}