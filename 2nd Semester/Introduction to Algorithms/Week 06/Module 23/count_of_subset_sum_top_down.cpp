#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subsetSum(int arr[], int n, int sum) { // TC: O(n*sum)
    if (n == 0) {
        return (sum == 0) ? 1 : 0;
    }

    if (dp[n][sum] != -1) return dp[n][sum];

    if (arr[n - 1] <= sum) {
        int op1 = subsetSum(arr, n - 1, sum - arr[n - 1]);
        int op2 = subsetSum(arr, n - 1, sum);
        return dp[n][sum] = op1 + op2;
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

    cout << subsetSum(arr, n, sum) << endl;

    return 0;
}