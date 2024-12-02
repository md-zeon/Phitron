#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dist[N];
bool visited[N];
vector<int> adjList[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            dist[v] = dist[u] + 1;
        }
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

    bfs(1);


    return 0;
}