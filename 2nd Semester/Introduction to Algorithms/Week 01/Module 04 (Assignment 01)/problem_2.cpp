//! Question: Write a C++ program that takes N integer numbers that are sorted and distinct. The next line will contain an integer k. You need to tell whether K exists in that array or not. If it exists, print its index otherwise print “Not Found”

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == k) return mid;
        else if (arr[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    int index = binarySearch(arr, n, k);
    (index != -1) ? cout << "Found at index " << index : cout << "Not Found";

    return 0;
}