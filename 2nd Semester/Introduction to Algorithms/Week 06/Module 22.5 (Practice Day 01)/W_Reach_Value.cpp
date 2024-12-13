#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll reachValue(ll val, ll target) {
    if (val == target) return 1;
    if (val > target) return 0;

    ll choice1 = reachValue(val * 10, target);
    ll choice2 = reachValue(val * 20, target);

    return choice1 + choice2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (reachValue(1, n) >= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}