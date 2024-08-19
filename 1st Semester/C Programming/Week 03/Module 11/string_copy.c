#include <stdio.h>
#include <string.h>

int main() {
    char a[10], b[10];
    scanf("%s %s", a, b);
    printf("Before Copy: %s %s\n", a, b);

    for(int i = 0; i <= strlen(b); i++) {
        a[i] = b[i];
    }

    // strcpy(a, b);
    
    printf("\nAfter Copy: %s %s", a, b);

    return 0;
}