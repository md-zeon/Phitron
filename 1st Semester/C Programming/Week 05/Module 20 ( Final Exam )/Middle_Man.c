#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int swapped = 0;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0) {
            break;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    if(n % 2 == 0) {
        printf("%d %d", a[n/2-1], a[n/2]);
    } else {
        printf("%d", a[n/2]);
    }


    return 0;
}