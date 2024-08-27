#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = a.size() - 1;
        bool flag = false;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (a[mid] == x) {
                flag = true;
                break;
            } else if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << (flag ? "found" : "not found") << endl;
    }

    return 0;
}