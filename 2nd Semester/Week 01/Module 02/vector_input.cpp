#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // type 01
    // vector<int> v;
    // for (int i = 0; i < n; i++) {
    //     int x; cin >> x;
    //     v.push_back(x);
    // }

    // type 02
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}