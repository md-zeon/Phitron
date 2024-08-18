#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = INT_MAX;
    int max = INT_MIN;
    int minIdx, maxIdx;

    for(int i = 0; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            minIdx = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }

    int temp = arr[minIdx];
    arr[minIdx] = arr[maxIdx];
    arr[maxIdx] = temp;

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}