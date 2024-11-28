#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "Visiting node: " << u << endl;
        // section 1: actions before exiting a node u
        for (int v : adjList[u]) {
            // section 2: actions before entering a new neighbour
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            // section 3: actions after exiting a neighbour
        }
        // section 4: actions after exiting a node u
    }
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

    bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "Level of node " << i << ": " << level[i] << endl;
    }


    return 0;
}