#include <stdio.h>

int main() {
    char s[100001];
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        } else {
            s[i] = ' ';
        }
    }

    printf("%s", s);

    return 0;
}