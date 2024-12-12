#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];


int knapsack(int n, int s, int val[], int wt[]) {
    if (n == 0 || s == 0) {
        return 0; // Base case: no items or no capacity
    }

    if (dp[n][s] != -1) {
        return dp[n][s];
    }

    if (wt[n - 1] <= s) { // If the item can be included
        int choice1 = val[n - 1] + knapsack(n - 1, s - wt[n - 1], val, wt); // Include
        int choice2 = knapsack(n - 1, s, val, wt);                         // Exclude
        return dp[n][s] = max(choice1, choice2);
    } else { // If the item cannot be included
        return dp[n][s] = knapsack(n - 1, s, val, wt);
    }
}

int main() {
    int n;
    cin >> n;

    int val[n], wt[n];
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, s, val, wt) << endl;

    return 0;
}
