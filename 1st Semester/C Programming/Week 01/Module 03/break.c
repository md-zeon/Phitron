#include <stdio.h>


int main() {

    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        if(i == 5) {
            printf("Breaking at %d\n", i);
            break;
        }
    }

    return 0;
}