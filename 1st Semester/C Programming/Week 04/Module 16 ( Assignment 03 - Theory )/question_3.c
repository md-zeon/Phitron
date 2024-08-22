/*
Question: Write a function named count_before_zero() which receives an array of integers and the size of that array and counts the number of elements in that array until you find zero and returns that count. Call that function in the main function and print the count there.
*/

#include <stdio.h>

int count_before_zero(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            break;
        }
        count++;
    }

    return count;
}

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = count_before_zero(arr, size);

    printf("%d\n", count);

    return 0;
}