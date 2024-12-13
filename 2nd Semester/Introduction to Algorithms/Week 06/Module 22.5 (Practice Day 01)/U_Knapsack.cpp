#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int index, int weight, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp) {
        if (index == 0 || weight == 0) {
            return 0;
        } else if (dp[index][weight] != -1) {
            return dp[index][weight];
        } else if (weights[index - 1] <= weight) {
            return dp[index][weight] = max(values[index - 1] + knapsack(index - 1, weight - weights[index - 1], weights, values, dp), knapsack(index - 1, weight, weights, values, dp));
        } else {
            return dp[index][weight] = knapsack(index - 1, weight, weights, values, dp);
        }
    }
    int main() {
        int items, max_weight;
        cin >> items >> max_weight;
        vector<int> weights(items);
        vector<int> values(items);
        for (int i = 0; i < items; i++) {
            cin >> weights[i] >> values[i];
        }
        vector<vector<int>> dp(items + 1, vector<int>(max_weight + 1, -1));
        cout << knapsack(items, max_weight, weights, values, dp) << endl;

        return 0;
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][s] << endl;

    return 0;
}

