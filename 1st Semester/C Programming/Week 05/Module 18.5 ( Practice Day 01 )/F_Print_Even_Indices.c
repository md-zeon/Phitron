#include <stdio.h>

void print_even_indices(int arr[], int n, int i) {
    if (i == n) {
        return;
    }

    print_even_indices(arr, n, i + 1);

    if(i % 2 == 0) {
        (i == 0) ? printf("%d", arr[i]) : printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    print_even_indices(arr, n, 0);

    return 0;
}