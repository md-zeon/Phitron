#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];

void dfs(int u) {
    visited[u] = true;

    for (int v : adjList[u]) {
        if (visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int node;
    cin >> node;
    dfs(1);

    cout <<"Depth of " << node << " = " << depth[node] << endl;


    return 0;
}