#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int INF = 1e9+10;
vector<pair<pii, int>> edges;
int dist[N];

void bellmenFord(int source, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        // all edges relaxation
        for (auto edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    init_code();
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    bellmenFord(1, n);

    for (int i = 1; i <= n; i++) {
        cout <<"Distance of node " << i << " is: " << dist[i] << endl;
    }
    

    return 0;
}