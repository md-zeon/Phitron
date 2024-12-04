#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int dist[N];
vector<int> cmp;

void dfs(int u) {
    visited[u] = true;
    cmp.push_back(u);

    for (int v : adjList[u]) {
        if (visited[v]) continue;
        dist[v] = dist[u] + 1;
        dfs(v);
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

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        cnt++;
        dfs(i);

        for (int node : cmp) {
            cout << node << " ";
        }
        cout << endl;
        cmp.clear();
    }

    cout << "Number of components: " << cnt << endl;

    return 0;
}