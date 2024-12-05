#include <bits/stdc++.h>
using namespace std;

#define INF 1e7

int main() {
    int n, e;
    cin >> n >> e;
    int dist[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF) cout << dist[i][j] << " ";
            else cout << "INF ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int negativeCycle = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Graph contains a negative-weight cycle" << endl;
    }

    cout << "Updated Matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF) cout << dist[i][j] << " ";
            else cout << "INF ";
        }
        cout << endl;
    }

    return 0;
}