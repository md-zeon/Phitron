#include <stdio.h>

char capital_to_small(char alpha) {
    if(alpha >= 'A' && alpha <= 'Z') {
        return alpha + 32;
    }

    return alpha;
}

int main() {
    char ch1, ch2, ch3;
    scanf("%c %c %c", &ch1, &ch2, &ch3);
    printf("%c\n%c\n%c\n", capital_to_small(ch1), capital_to_small(ch2), capital_to_small(ch3));

    return 0;
}