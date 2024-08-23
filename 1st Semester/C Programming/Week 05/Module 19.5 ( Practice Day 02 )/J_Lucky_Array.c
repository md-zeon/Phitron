#include <stdio.h>
#include <limits.h>

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int frequency = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == min) {
            frequency++;
        }
    }

    if(frequency % 2 == 1) {
        printf("Lucky\n");
    } else {
        printf("Unlucky\n");
    }

    return 0;
}