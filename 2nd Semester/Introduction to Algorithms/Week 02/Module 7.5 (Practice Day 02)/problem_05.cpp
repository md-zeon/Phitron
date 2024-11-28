#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
vector<vector<int>> components;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> component;
    while (!q.empty()) {
        int u = q.front();
        component.push_back(u);
        q.pop();
        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
        }
    }
    components.push_back(component);
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

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        bfs(i);
    }

    cout << "Number of connected components: " << components.size() << endl;

    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}