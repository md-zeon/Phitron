#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 10;
int d[N][N];

void distInitialize(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
}

void printMatrix(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] == INF) cout << "X ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    distInitialize(n, n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }

    cout << "Before Floyd Warshall: " << endl;
    printMatrix(n, n);

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << "After Floyd Warshall: " << endl;
    printMatrix(n, n);

        

    return 0;
}