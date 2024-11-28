#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
vector<int> level(N, -1);
vector<int> visited(N, false);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (visited[v] == true) continue;
            visited[v] = true;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
}


int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    size_t l;
    cin >> l;
    bfs(0);
    vector<int> result;
    for (int i = 0; i < N; i++) {
        if (level[i] == l) {
            result.push_back(i);
        }
    }

    if (result.empty()) {
        cout << -1;
    } else {
        sort(result.begin(), result.end());
        for (int shop : result) {
            cout << shop << " ";
        }
    }

    cout << endl;


    return 0;
}