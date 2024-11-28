#include <bits/stdc++.h>
using namespace std;

const int N = 25;
vector<int> adjList[N];
bool visited[N];

void dfs(int u, int &count) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (visited[v] == true) continue;
        count++;
        dfs(v, count);
        visited[v] = true;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int k;
    cin >> k;

    int count = 0;
    dfs(k, count);

    cout << count << endl;
    
    return 0;
}