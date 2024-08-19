#include <stdio.h>

int main() {
    char s[1001];
    scanf("%s", s);
    int capital, small;
    capital = small =  0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            capital++;
        } else if(s[i] >= 'a' && s[i] <= 'z') {
            small++;
        }
    }

    printf("%d %d", capital, small);

    return 0;
}