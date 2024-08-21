#include <stdio.h>

char small_to_capital(char alpha) {
    if(alpha >= 'a' && alpha <= 'z') {
        return alpha - 32;
    }

    return alpha;
}

int main() {
    char ch1, ch2, ch3;

    scanf("%c %c %c", &ch1, &ch2, &ch3);

    printf("%c\n%c\n%c\n", small_to_capital(ch1), small_to_capital(ch2), small_to_capital(ch3));

    return 0;
}