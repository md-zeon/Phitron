#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subsetSum(int arr[], int n, int sum) { // TC: O(n*sum)
    if (n == 0) {
        return (sum == 0);
    }

    if (dp[n][sum] != -1) return dp[n][sum];

    if (arr[n - 1] <= sum) {
        bool op1 = subsetSum(arr, n - 1, sum - arr[n - 1]);
        bool op2 = subsetSum(arr, n - 1, sum);
        return dp[n][sum] = op1 || op2;
    } else {
        return dp[n][sum] = subsetSum(arr, n - 1, sum);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = -1;
        }
    }

    if (subsetSum(arr, n, sum)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}