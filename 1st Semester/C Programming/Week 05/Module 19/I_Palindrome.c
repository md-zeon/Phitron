#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);
    int i = 0, j = strlen(str) - 1;
    int palindrome = 1;
    while (i < j) {
        if (str[i] != str[j]) {
            palindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}