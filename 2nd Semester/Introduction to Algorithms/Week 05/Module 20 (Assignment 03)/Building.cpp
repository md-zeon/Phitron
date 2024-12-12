#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rank, size;

public:
    // Constructor: Initializes the DSU for n elements
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i; // Each node is its own parent
        }
    }

    // Find function with path compression
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    // Union function with union by rank
    void union_by_rank(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA != leaderB) {
            if (rank[leaderA] < rank[leaderB]) {
                parent[leaderA] = leaderB;
            }
            else if (rank[leaderA] > rank[leaderB]) {
                parent[leaderB] = leaderA;
            }
            else {
                parent[leaderB] = leaderA;
                rank[leaderA]++;
            }
        }
    }

    // Union function with union by size
    void union_by_size(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA != leaderB) {
            if (size[leaderA] < size[leaderB]) {
                parent[leaderA] = leaderB;
                size[leaderB] += size[leaderA];
            } else {
                parent[leaderB] = leaderA;
                size[leaderA] += size[leaderB];
            }
        }
    }
};

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long totalCost = 0;
    // int edgeAdded = 0;

    for (Edge edge : edges) {
        // Check if the nodes are in the same component
        if (dsu.find(edge.u) == dsu.find(edge.v)) {
            continue;
        }
        // Union the components
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.union_by_rank(edge.u, edge.v);
            totalCost += (long long) edge.w;
            // edgeAdded++;
        }
    }

    bool isConnected = true;
    int root = dsu.find(1);

    for (int i = 2; i <= n; i++) {
        if (dsu.find(i) != root) {
            isConnected = false;
            break;
        }
    }

    // if (edgeAdded != n - 1) {
    //     cout << -1 << endl;
    // } else {
    //     cout << totalCost << endl;
    // }

    if (!isConnected) {
        cout << "-1" << endl;
    } else {
        cout << totalCost << endl;
    }

    return 0;
}