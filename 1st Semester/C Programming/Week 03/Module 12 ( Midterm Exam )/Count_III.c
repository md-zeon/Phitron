#include <stdio.h>

int main() {
    char s[1001];
    scanf("%s", s);
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        printf("%c - %d\n", 'a' + i, freq[i]);
    }

    return 0;
}