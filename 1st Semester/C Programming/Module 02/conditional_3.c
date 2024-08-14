#include <stdio.h>

int main() {
    int tk;

    scanf("%d", &tk);

    if(tk >= 5000)
    {
        printf("Cox's Bazaar Jabo\n");
        if(tk >= 10000) {
            printf("Saint Martin Jabo\n");
        } else {
            printf("Ferot Chole Ashbo\n");
        }
    }
    else
    {
        printf("Khotao Jabo Na\n");
    }

    return 0;
}