#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int l = 0;
    int r = n - 1;
    bool flag = false;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == key) {
            flag = true;
            break;
        }

        if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}