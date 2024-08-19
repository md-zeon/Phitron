#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    scanf("%99s %99s", str1, str2);

    int i = 0;
    while(1) {
        if(str1[i] == '\0' && str2[i] == '\0') {
            printf("Equal\n");
            break;
        } else if(str1[i] == '\0' || str1[i] < str2[i]) {
            printf("Str1 is Less than Str2\n");
            break;
        } else if(str2[i] == '\0' || str1[i] > str2[i]) {
            printf("Str2 is Less than Str1\n");
            break;
        }

        i++;
    }

    return 0;
}