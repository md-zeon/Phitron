#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int heights[n+1], dp[n+1];
    for(int i=1; i<=n; i++) {
        cin >> heights[i];
    }
    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);
    for(int i=3; i<=n; i++) {
        int choice1 = dp[i-2] + abs(heights[i] - heights[i-2]); // step 2
        int choice2 = dp[i-1] + abs(heights[i] - heights[i-1]); // step 1
        dp[i] = min(choice1, choice2);
    }
    cout << dp[n];

    return 0;
}