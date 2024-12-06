#include <bits/stdc++.h>
using namespace std;

class DSU { // Disjoint Set Union
private:
    vector<int> parent, rank; 

public:
    // Constructor: Initializes the DSU for n elements
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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
    void union_sets(int a, int b) {
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
};

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    vector<Edge> ans;

    if (e == 0) {
        cout << "No edges in the graph.\n";
        return 0;
    }

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);

    int totalWeight = 0;
    for (Edge val : edges)
    {
        int a = val.u;
        int b = val.v;
        int w = val.w;
        int leaderA = dsu.find(a);
        int leaderB = dsu.find(b);

        if (leaderA == leaderB)
            continue;
        dsu.union_sets(a, b);
        ans.push_back(val);
        totalWeight += w;
    }

    for (Edge val : ans)
    {
        cout << val.u << " " << val.v << " " << val.w << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
