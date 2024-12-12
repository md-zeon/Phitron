#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int s, vector<int> wt, vector<int> val, vector<vector<int>> &save) {
    if (n == 0 || s == 0) {
        return 0;
    }

    if (save[n][s] != -1) {
        return save[n][s];
    }

    if (wt[n-1] <= s) {
        int pick = val[n-1] + knapsack(n-1, s-wt[n-1], wt, val, save);
        int notPick = knapsack(n-1, s, wt, val, save);
        return save[n][s] = max (pick, notPick);
    } else {
        return save[n][s] = knapsack(n-1, s, wt, val, save);
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> wt(n), val(n);
    vector<vector<int>> save(n+1, vector<int> (s+1, -1));

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n, s, wt, val, save) << endl;



    return 0;
}