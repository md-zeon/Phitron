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

bool dfs(int u, int p = -1) {
    visited[u] = true;
    bool cycleExists = false;

    for (int v : adjList[u]) {
        if (v == p) continue;
        if (visited[v] == true) return true;
        cycleExists |= dfs(v, u);
        if (cycleExists) return true;
        // if (dfs(v, u) == true) return true;
    }
    // return false;
    return cycleExists;
}

int main() {
    init_code();
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        if (dfs(i) == true) {
            cycle = true;
            break;
        }
    }

    if (cycle) cout << "Cycle detected" << endl;
    else cout << "No cycle detected" << endl;
    

    return 0;
}