#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        edges.push_back(ed);
    }

    int dist[n+1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            Edge ed = edges[j];
            if (dist[ed.u] + ed.w < dist[ed.v]) {
                dist[ed.v] = dist[ed.u] + ed.w;
            }
        }
    }

    bool negativeCycle = false;
    for (int i = 0; i < edges.size(); i++) {
        Edge ed = edges[i];
        if (dist[ed.u] + ed.w < dist[ed.v]) {
            negativeCycle = true;
        }
    }

    if (negativeCycle) {
        cout << "Graph contains negative cycle" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << "Distance of node " << i << " is: " << dist[i] << endl;
        }
    }
    

    return 0;
}