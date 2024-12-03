#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adjList[N];
int dist[N];
int parent[N];
bool visited[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    parent[s] = -1;
    visited[s] = true;

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
    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int source, destination;
    cin >> source >> destination;
    bfs(source);
    cout << "Shortest distance from " << source << " to " << destination << " is: " << dist[destination] << endl;

    if (visited[destination] == true) {
        vector<int> path;
        int x = destination;

        while (x != -1) {
            // cout << x << " ";
            path.push_back(x);
            x = parent[x];
        }

        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path exists from " << source << " to " << destination << endl;
    }

    return 0;
} 