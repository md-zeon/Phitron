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
vector<pii> adjList[N];
int dist[N];

void bellmenFord(int source, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        // all edges relaxation
        for (int u = 1; u <= n; u++) {
            for (pii vpair : adjList[u]) {
                int v = vpair.first;
                int w = vpair.second;
                if (dist[u] == INF) continue;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
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
        adjList[u].push_back({v, w});
    }

    bellmenFord(1, n);

    for (int i = 1; i <= n; i++) {
        cout <<"Distance of node " << i << " is: " << dist[i] << endl;
    }
    

    return 0;
}