#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int counter[7] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        counter[arr[i]]++;
    }

    for(int i = 0; i < 7; i++) {
        printf("There are %d %ds\n", counter[i], i);
    }


    return 0;
}