#include <stdio.h>

int main() {
    int password = 1999;
    int x;

    while(scanf("%d", &x) != EOF) {
        if(x == password) {
            printf("Correct\n");
            break;
        } else {
            printf("Wrong\n");
        }
    }

    return 0;
}