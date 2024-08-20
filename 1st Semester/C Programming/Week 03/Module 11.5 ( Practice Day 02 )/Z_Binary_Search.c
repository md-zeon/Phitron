#include <stdio.h>

void merge(int arr[], int si, int mid, int ei) {
    int tempSize = ei-si+1;
    int temp[tempSize];
    int i = si;
    int j = mid+1;
    int k = 0;
    
    while(i <= mid && j <= ei) {
        if(arr[i] < arr[j]) {
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
    
    for(int k = 0, i = si; k < tempSize; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[],int si, int ei) {
    if(si >= ei) {
        return;
    }
    int mid = si + (ei- si) / 2;
    
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
}

void binarySearch(int arr[], int n, int target) {
    int si = 0, ei = n - 1;
    while(si <= ei) {
        int mid = si + (ei - si) / 2;
        if(arr[mid] == target) {
            printf("found\n");
            return;
        } else if (arr[mid] < target) {
            si = mid+1;
        } else {
            ei = mid-1;
        }
    }
    
    printf("not found\n");
}

int main() {
    // Write C code here
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    
    for(int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        binarySearch(arr, n, x);
    }
    

    return 0;
}