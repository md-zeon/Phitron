#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

const int N = 1e5 + 5;
vector<int> adjList[N];
vector<bool> visited(N, false);
int depth[N];
int height[N];

void dfs(int u) {
    visited[u] = true;

    for (auto v : adjList[u])
    {
        if (visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
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

    dfs(1);

    for (int i = 1; i < n; i++)
    {
        cout << "Depth of Node " << i << ": ";
        cout << depth[i] << endl;
    }
    cout << "***********************" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << "Height of Node " << i << ": ";
        cout << height[i] << endl;
    }

    return 0;
}