#include <stdio.h>

int length_of_string(char str[], int l) {
    if(str[l] == '\0') return l;
    length_of_string(str, (l+1));
}

int fun(char a[], int i) {
    if(a[i] == '\0') return 0;
    int l = fun(a, (i+1));
    return l+1;
}

int main() {

    char str[] = "Hello";
    printf("%d\n", length_of_string(str, 0));
    printf("%d\n", fun(str, 0));
    

    return 0;
}