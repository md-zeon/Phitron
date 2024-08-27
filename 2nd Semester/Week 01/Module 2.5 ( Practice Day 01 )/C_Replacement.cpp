#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 0) {
            replace(v.begin(), v.end(), v[i], 1);
        } else if (v[i] < 0) {
            replace(v.begin(), v.end(), v[i], 2);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        (i == v.size() - 1) ? cout << v[i] : cout << v[i] << " ";
    }

    return 0;
}