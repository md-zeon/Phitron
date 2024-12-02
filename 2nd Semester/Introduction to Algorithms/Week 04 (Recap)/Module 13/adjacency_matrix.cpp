#include <bits/stdc++.h>
using namespace std;

int main() {
    int node, edge;
    cin >> node >> edge;

    int adj[node+1][node+1] = {0};

    while (edge--) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i <= node; i++) {
        for (int j = 1; j <= node; j++) {
            if (i == j) adj[i][j] = 1;
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}