#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long int> prefixSum(n); // kromojojito gonosongkha

    prefixSum[0] = a[0];

    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == 0) {
            cout << prefixSum[r] << endl;
        } else {
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
        }
    }

    return 0;
}