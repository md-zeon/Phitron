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
bool visited[N];

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adjList[u]) {
        if (visited[v] == true) continue;
        dfs(v);
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
        }
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

    int cc = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        cc++;
        cout << "Component " << cc << ": ";
        // dfs(i);
        bfs(i);
        cout << endl;
    }

    // cout << "Number of connected components: " << cc << endl;

    

    return 0;
}