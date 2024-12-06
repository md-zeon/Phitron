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
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int n, e;
    cin >> n >> e;
    DSU dsu(n);
    vector<Edge> edges;
    vector<Edge> ans;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);

    int totalWeight = 0;
    for (Edge edge : edges) {
        int a = edge.u;
        int b = edge.v;
        int w = edge.weight;
        int leaderA = dsu.find(a);
        int leaderB = dsu.find(b);
        
        if (leaderA == leaderB) continue;
        ans.push_back(edge);
        dsu.union_by_rank(a, b);
        totalWeight += w;
    }

    if (ans.size() == n - 1) {
        cout << totalWeight << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}