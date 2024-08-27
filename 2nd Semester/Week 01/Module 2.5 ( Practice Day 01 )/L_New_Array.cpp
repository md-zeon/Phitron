#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> v(b);
    v.insert(v.begin()+n, a.begin(), a.end());

    for (int i = 0; i < v.size(); i++) {
        (i == v.size() - 1) ? cout << v[i] : cout << v[i] << " ";
    }

    return 0;
}