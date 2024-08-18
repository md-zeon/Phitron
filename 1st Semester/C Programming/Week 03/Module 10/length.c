#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);

    int i = 0, count = 0;

    while(a[i] != '\0') {
        count++;
        i++;
    }

    printf("%d\n%d", count, strlen(a));

    return 0;
}