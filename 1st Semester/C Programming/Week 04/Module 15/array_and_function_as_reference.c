#include <stdio.h>

void func(char arr[]) {
    arr[0] = 'G';
}

int main() {
    char arr[20] = "Hello";
    func(arr);

    printf("%s\n", arr);

    return 0;
}