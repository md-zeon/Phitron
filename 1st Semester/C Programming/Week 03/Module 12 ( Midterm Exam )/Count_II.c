#include <stdio.h>

int main() {
    char s[1001];
    scanf("%s", s);
    int vowels = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels++;
        }
    }

    printf("%d\n", vowels);

    return 0;
}