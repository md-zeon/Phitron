#include <stdio.h>

int my_len(char *str) {
    int i = 0;

    while(str[i] != '\0') {
        i++;
    }

    return i;
}

int main() {
    char str[] = "Hello";
    printf("%d", my_len(str));


    return 0;
}