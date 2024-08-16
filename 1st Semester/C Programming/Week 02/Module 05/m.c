#include <stdio.h>

int main() {
    // Given a letter X. Determine whether X is Digit or Alphabet and if it is Alphabet determine if it is Capital Case or Small Case.

    char x;
    scanf("%c", &x);

    if(x >= 'a' && x <= 'z') {
        printf("ALPHA\nIS SMALL\n");
    } else if(x >= 'A' && x <= 'Z') {
        printf("ALPHA\nIS CAPITAL\n");
    } else {
        printf("IS DIGIT\n");
    }

    return 0;
}