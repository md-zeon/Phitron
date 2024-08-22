#include <stdio.h>

void print(int n) {
    if(n == 0) return;
    printf("%d ", n);
    print(n - 1);
}

void fun(int i) {
    if(i == 6) return;
    fun(i+1);
    printf("%d ", i);
}

int main() {
    int n = 5;
    print(n);
    printf("\n");
    fun(1);
    
    return 0;
}