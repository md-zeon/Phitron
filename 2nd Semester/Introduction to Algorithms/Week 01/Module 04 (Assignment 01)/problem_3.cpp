//! Question: You are given an array of N positive integers. The next line will contain an integer K. You need to tell whether there exists more than one occurrence of K in that array or not.
// If there exists more than one occurrence of K print YES, Otherwise print NO.
// See the sample input-output for more clarification.
// The given array will be sorted in increasing order. And it is guaranteed that at least one occurrence of K will exist.	 You must solve this in O(logn) complexity.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int count = 0;
    int index = binarySearch(arr, k);
    if (arr[index] == k) {
        count++;
        if (arr[index + 1] == k) {
            count++;
        }
    }

    if (count > 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}