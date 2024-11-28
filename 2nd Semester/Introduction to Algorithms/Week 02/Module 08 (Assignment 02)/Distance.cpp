#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];

void bfs(int s, vector<int> &distance, bool visited[]) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    distance[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            distance[v] = distance[u] + 1;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int query;
    cin >> query;

    for (int i = 0; i < query; i++) {
        bool visited[N] = {false};
        vector<int> distance(N, -1);
        int source, destination;
        cin >> source >> destination;
        bfs(source, distance, visited);
        cout << distance[destination] << endl;
    }

    return 0;
}