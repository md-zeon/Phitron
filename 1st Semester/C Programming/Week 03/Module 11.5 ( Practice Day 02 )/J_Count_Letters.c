#include <stdio.h>
#include <string.h>

int main() {
    char ch;
    int counter[26] = {0};

    while(scanf("%c", &ch) != EOF) {
        int charIdx = ch - 'a';
        counter[charIdx]++;
    }

    for(int i = 0; i < 26; i++) {
        if(counter[i] != 0) {
            printf("%c : %d\n", i + 'a', counter[i]);
        }
    }

    return 0;
}