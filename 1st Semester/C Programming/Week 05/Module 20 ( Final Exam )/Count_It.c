#include <stdio.h>

int main() {
    char str[1001];
    fgets(str, 1001, stdin);

    int capital = 0, small = 0, space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            capital++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            small++;
        } else if (str[i] == ' ') {
            space++;
        }
    }

    printf("Capital - %d\n", capital);
    printf("Small - %d\n", small);
    printf("Spaces - %d\n", space);

    return 0;
}