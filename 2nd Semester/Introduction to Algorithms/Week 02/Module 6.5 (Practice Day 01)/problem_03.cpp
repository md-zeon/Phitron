#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> adjList(n + 1);
    vector<int> adjList[n + 1];
    // Input the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    // convert to adjacency matrix
    int adjMatrix[n + 1][n + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j : adjList[i]) {
            adjMatrix[i][j] = 1;
        }
    }
    
    // print the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }    
        cout << endl;
    }




    return 0;
}