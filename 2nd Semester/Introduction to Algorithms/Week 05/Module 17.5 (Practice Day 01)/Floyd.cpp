#include <bits/stdc++.h>
using namespace std;

#define INF 1e7

int main() {
    int n;
    cin >> n;
    int a[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                a[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    int maxDist = INT_MIN;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || a[i][j] == INF) continue;
            maxDist = max(maxDist, a[i][j]);
        }
    }

    cout << maxDist << endl;
    return 0;
}