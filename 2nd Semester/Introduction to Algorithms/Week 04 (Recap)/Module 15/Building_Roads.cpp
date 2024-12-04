#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adjList[N];
bool visited[N];
vector<int> component;
vector<vector<int>> components;

void dfs(int u) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adjList[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components.push_back(component);
            component.clear();
        }
    }

    cout << components.size() - 1 << endl;
    for (int i = 0; i < components.size() - 1; i++) {
        cout << components[i][components[i].size() - 1] << " " << components[i + 1][0] << endl;
    }
    return 0;
}