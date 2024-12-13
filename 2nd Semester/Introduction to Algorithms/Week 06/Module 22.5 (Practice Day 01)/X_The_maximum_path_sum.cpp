#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function with memoization
int rec(const vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) { // Base case: top-left corner
        return grid[0][0];
    }
    if (i < 0 || j < 0) { // Invalid cell
        return INT_MIN;
    }
    if (dp[i][j] != -1) { // If already computed
        return dp[i][j];
    }

    // Recursive calls for top and left cells
    int fromTop = rec(grid, i - 1, j, dp);
    int fromLeft = rec(grid, i, j - 1, dp);

    // Store the result in dp table
    return dp[i][j] = grid[i][j] + max(fromTop, fromLeft);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // DP table for memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Compute the maximum path-sum to the bottom-right corner
    cout << rec(grid, n - 1, m - 1, dp) << endl;

    return 0;
}
