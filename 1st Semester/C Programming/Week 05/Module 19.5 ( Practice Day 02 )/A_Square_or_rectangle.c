#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == b) {
            printf("Square\n");
        } else {
            printf("Rectangle\n");
        }
    }

    return 0;
}