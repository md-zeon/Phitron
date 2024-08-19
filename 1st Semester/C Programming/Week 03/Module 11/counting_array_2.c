#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int counter[26] = {0};
    for(int i = 0; i < strlen(s); i++) {
        char charIdx = s[i] - 'a';
        counter[charIdx]++;
    }

    for(int i = 0; i < 26; i++) {
        if(counter[i] > 0) {
            printf("%c = %d\n", i + 'a', counter[i]);
        }
    }
    

    return 0;
}