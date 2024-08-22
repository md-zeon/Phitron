#include <stdio.h>

int max(int arr[], int n, int i) {
    if (i == n - 1) {
        return arr[i];
    }
    int m = max(arr, n, i + 1);
    if (arr[i] > m) {
        return arr[i];
    }
    return m;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d", max(a, n, 0));


    return 0;
}