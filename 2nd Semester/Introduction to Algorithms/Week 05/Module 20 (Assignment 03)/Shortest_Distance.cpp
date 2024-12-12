#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    long long int dist[n+1][n+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e15;
        }
    }

    while (e--) {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == 1e15) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
    

    return 0;
}