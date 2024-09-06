#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    bool duplicate = false;

    for(int i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            duplicate = true;
            break;
        }
    }

    if(duplicate) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}