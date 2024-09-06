#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long int> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    reverse(prefix_sum.begin(), prefix_sum.end());

    for (int i = 0; i < n; i++) {
        (i == n-1) ? cout << prefix_sum[i] : cout << prefix_sum[i] << " ";
    }

    return 0;
}