#include <stdio.h>

void print(int n) {
    if(n == 0) {
        return;
    }
    print(n - 1);
    printf("%d ", n);
}

void fun(int i) {
    if(i == 6) {
        return;
    }
    printf("%d ", i);
    fun(i + 1);
}

int main() {
    int n = 5;
    print(n);


    return 0;
}