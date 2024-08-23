#include <stdio.h>
#include <limits.h>

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

void merge(int arr[], int si, int mid, int ei) {
    int temp[ei - si + 1];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= ei) {
        if(arr[i] > arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= ei) {
        temp[k++] = arr[j++];
    }

    for(int i = si, k = 0; k < ei-si+1; i++) {
        arr[i] = temp[k++];
    }
}
        

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    long long int sum = 0;
    for (int i = 0; i < k; i++) {
        if(arr[i] > 0) {
            sum += arr[i];
        }
    }

    printf("%lld\n", sum);

    return 0;
}