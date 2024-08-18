#include <stdio.h>

int main() {
    char str[1000001];
    fgets(str, 1000001, stdin);

    int i = 0;
    while(str[i] != '\\' && str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }

    return 0;
}