#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = INT_MIN;
    while(n--) {
        int x;
        cin >> x;
        m = max(m, x);
    }

    cout << m << endl;

    return 0;
}