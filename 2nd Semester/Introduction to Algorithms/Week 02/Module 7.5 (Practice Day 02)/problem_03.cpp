#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

bool bfs(int s) {
    queue<pair<int,int>> q;
    q.push({s, -1});
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();
        for (int v : adjList[u]) {
            if (v == p) continue;
            if (visited[v] == true) return true;
            q.push({v, u});
            visited[v] = true;
        }
    }
    return false;
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

    bool hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        hasCycle = bfs(i);
        if (hasCycle) break;
    }
    if (hasCycle) cout << "Cycle exists";
    else cout << "Cycle does not exist";

    return 0;
}