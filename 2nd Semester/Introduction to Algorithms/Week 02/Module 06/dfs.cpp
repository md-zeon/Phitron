#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 5;
vector<int> adjList[N];
vector<bool> visited(N, false);

void dfs(int u)
{
    // section 1: actions before entering a node u
    visited[u] = true;
    cout << "Visiting node: " << u << endl;

    for (int v : adjList[u])
    {
        // section 2: actions before entering a new neighbour
        if (visited[v] == true) continue;
        dfs(v);
        // section 3: actions after exiting a neighbour
    }
    // section 4: actions after exiting a node
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);

    cout << "Visited nodes: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> " << visited[i] << endl;
    }


    return 0;
}