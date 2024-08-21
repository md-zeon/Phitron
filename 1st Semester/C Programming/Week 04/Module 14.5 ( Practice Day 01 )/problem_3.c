#include <stdio.h>

int char_to_ascii(char ch) {
    return ch;
}

int main() {
    char ch1, ch2, ch3;
    scanf("%c %c %c", &ch1, &ch2, &ch3);
    printf("%d\n", char_to_ascii(ch1));
    printf("%d\n", char_to_ascii(ch2));
    printf("%d\n", char_to_ascii(ch3));


    return 0;
}