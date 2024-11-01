/*
Question: You are given two sorted arrays arr1 and arr2 in descending order.Your task is 
to merge these two arrays into a new array result using the merge sort technique, 
but Instead of merging the arrays in ascending order, you need to merge them in 
descending order to create the result array. You cannot use stl sort function here.
*/

#include <iostream>
using namespace std;

void merge(int arr1[], int m, int arr2[], int n, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (arr1[i] >= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < m) {
        result[k++] = arr1[i++];
    }
    while (j < n) {
        result[k++] = arr2[j++];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {8, 6, 4, 2};
    int arr2[] = {7, 5, 3, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    int result[m + n];
    merge(arr1, m, arr2, n, result);

    cout << "Array 1: ";
    printArray(arr1, m);
    cout << "Array 2: ";
    printArray(arr2, n);
    cout << "Merged Array: ";
    printArray(result, m + n);

    return 0;
}