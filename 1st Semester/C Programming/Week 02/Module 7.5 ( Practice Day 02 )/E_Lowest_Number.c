#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == min) {
            printf("%d %d\n", arr[i], i+1);
            break;
        }
    }
    

    return 0;
}