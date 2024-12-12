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

int main() {
    int n, e;
    cin >> n >> e;
    DSU ds(n);
    int cycleEdges = 0;
    while(e--) {
        int u, v;
        cin >> u >> v;
        if (ds.find(u) == ds.find(v)) {
            cycleEdges++;
        } else {
            ds.union_by_rank(u, v);
        }
    }

    cout << cycleEdges << endl;

    return 0;
}