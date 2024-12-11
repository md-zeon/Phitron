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

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    cin >> n >> m;
    DSU ds(n);
    vector<Edge> edges;
    int total_cost = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);

    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        int leaderU = ds.find(u);
        int leaderV = ds.find(v);
        if (leaderU != leaderV) {
            total_cost += w;
            ds.union_by_rank(u, v);
        }
    }

    cout << total_cost << endl;

    return 0;
}