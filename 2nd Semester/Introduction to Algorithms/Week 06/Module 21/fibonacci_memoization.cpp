#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int N = 1e5 + 5;
lli save[N];

lli fib(int n) { // O(n)
    if (n == 0 || n == 1) {
        return 1;
    }

    // memoization
    if (save[n] != -1) {
        return save[n];
    }
    lli ans1 = fib(n - 1);
    lli ans2 = fib(n - 2);
    save[n] = ans1 + ans2;

    return save[n];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        save[i] = -1;
    }

    cout << fib(n) << endl;
    return 0;
}