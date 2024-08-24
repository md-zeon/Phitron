#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        (i == n-1) ? cout << arr[i] << endl : cout << arr[i] << " ";
    }

    return 0;
}