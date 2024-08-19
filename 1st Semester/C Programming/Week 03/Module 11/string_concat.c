#include <stdio.h>
#include <string.h>

int main() {
    char s1[30], s2[10];

    scanf("%s %s", s1, s2);

    int i = strlen(s1), j = 0; 

    while(j != strlen(s2) + 1) {
        s1[i] = s2[j];
        i++;
        j++;
    }

    // strcat(s1, s2);

    printf("%s", s1);

    return 0;
}