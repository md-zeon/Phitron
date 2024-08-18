#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1001];
    scanf("%s", s);
    int i = 0, j = strlen(s) - 1;
    bool isPalindrome = true;
    
    while(i < j) {
        if(s[i] != s[j]) {
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }

    if(isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}