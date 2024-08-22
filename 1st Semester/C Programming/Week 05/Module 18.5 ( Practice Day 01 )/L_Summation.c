#include <stdio.h>


long long int sum(int a[], int n, int i) {
    if(i == n) return 0;

    return a[i] + sum(a, n, i+1);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%lli\n", sum(a, n, 0));

    return 0;
}