#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    printf("%d %d\n", even, odd);

    return 0;
}