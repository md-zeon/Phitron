#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adjList[u]) {
        if (visited[v] == true) continue;
        dfs(v);
    }
}


int main() {
    int n, e;
    cin >> n >> e;
    
    while (e--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);

    return 0;
}