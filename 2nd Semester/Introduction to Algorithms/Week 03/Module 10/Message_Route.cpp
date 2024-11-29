#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adjList[N];
vector<bool> visited(N, false);
vector<int> level(N);
vector<int> parent(N);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
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

    bfs(1);

    cout << level[n] + 1 << endl;

    vector<int> path;
    int curr = n;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }



    return 0;
}