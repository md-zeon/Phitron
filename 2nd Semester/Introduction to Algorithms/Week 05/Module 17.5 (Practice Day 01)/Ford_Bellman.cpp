#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

void BellmenFord(vector<Edge> &edges, int n, int m) {
    vector<int> dist(n+1, 30000);
    dist[1] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (Edge edge : edges) {
            if (dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    dist.erase(dist.begin());

    for (int i : dist) {
        cout << i << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    BellmenFord(edges, n, m);
    

    return 0;
}