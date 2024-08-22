#include <stdio.h>

void print_array(int arr[], int n, int i) {
    if(i == n) return;
    printf("%d ", arr[i]);
    print_array(arr, n, i+1);
}
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    print_array(arr, 5, 0);

    return 0;
}