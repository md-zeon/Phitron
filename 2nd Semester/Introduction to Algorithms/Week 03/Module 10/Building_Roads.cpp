#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[u] = true;

    for (int v : adjList[u]) {
        if (visited[v] == true) continue;
        dfs(v, adjList, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> leaders;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        leaders.push_back(i);
        dfs(i, adjList, visited);
    }

    cout << leaders.size() - 1 << endl;
    for (int node : leaders) {
        cout << node << " ";
    }




    return 0;
}