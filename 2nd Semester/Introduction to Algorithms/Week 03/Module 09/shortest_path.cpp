#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int dist[N];
int parent[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            dist[v] = dist[u] + 1;
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

    int source, destination;
    cin >> source >> destination;

    bfs(source);
    cout << dist[destination] << endl;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) {
            cout << "Parent of node " << i << " -> " << parent[i] << endl;
        }
    }

    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int i : path) {
        cout << i << " ";
    }

    cout << endl;
    
    

    return 0;
}