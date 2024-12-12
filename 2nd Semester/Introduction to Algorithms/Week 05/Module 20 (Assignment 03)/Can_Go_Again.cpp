#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool bellmanFord(vector<Edge> &edges, vector<long long> &dist, int n, int src) {
    dist[src] = 0;

    // Relaxation
    for (int i = 1; i <= n-1; i++) {
        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != 1e15 && dist[u] + (long long) w < dist[v]) { // Check for overflow
                dist[v] = dist[u] + (long long) w;
            }
        }
    }

    // Check for negative cycle
    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dist[u] != 1e15 && dist[u] + (long long) w < dist[v]) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    vector<long long> dist(n+1, 1e15);

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    int src;
    cin >> src;
    if (bellmanFord(edges, dist, n, src)) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        int t;
        cin >> t;

        while (t--) {
            int dest;
            cin >> dest;
            if (dist[dest] == 1e15) {
                cout << "Not Possible" << endl;
            } else {
                cout << dist[dest] << endl;
            }
        }
    }

    return 0;
}