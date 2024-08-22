#include <stdio.h>
#include <string.h>

void print(char arr[]) {
    printf("%s\n", arr);
    printf("Length = %d\n", strlen(arr));
}

char* func(char *ch) {
    return ch;
}

int main() {
    char arr[20] = "Hello";

    print(arr);
    func(arr);
    char *ch = func(arr);
    printf("%s\n", ch);
    return 0;
}