#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Edge case: only one house
        if (n == 1) {
            cout << "Case " << c << ": " << a[0] << endl;
            continue;
        }
        
        int dp[n];
        dp[0] = a[0];  // Rob the first monster
        dp[1] = max(a[0], a[1]);  // Either rob the first or second monster
        
        for (int i = 2; i < n; i++) {
            // For each monster, decide whether to rob it or skip it
            dp[i] = max(dp[i-1], a[i] + dp[i-2]);
        }
        
        cout << "Case " << c << ": " << dp[n - 1] << endl;
    }
    return 0;
}
