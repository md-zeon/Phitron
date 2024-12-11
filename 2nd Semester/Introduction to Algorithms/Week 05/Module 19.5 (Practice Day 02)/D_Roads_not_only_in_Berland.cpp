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
    int n;
    cin >> n;
    DSU ds(n);
    vector<vector<int>> list1; // list1 is the list of edges that are in the same components
    vector<vector<int>> list2; // list2 is the list of edges that are not in the same components
 
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (ds.find(u) == ds.find(v)) { // if the nodes are in the same component
            list1.push_back({u, v});
        } else { // if the nodes are not in the same component
            ds.union_by_rank(u, v);
        }
    }
 
    // find the edges that are not in the same components
    for (int u = 1; u <= n; u++) {
        // check all the nodes that are not in the same component
        for (int v = u + 1; v <= n; v++) {
            // if the nodes are in the same component, continue
            if (ds.find(u) == ds.find(v)) continue;
 
            // if the nodes are not in the same component, add the edge to the list
            list2.push_back({u, v});
            ds.union_by_rank(u, v);
        }
    }
 
    cout << list2.size() << endl; // print the number of edges that are not in the same components
 
    for (int i = 0; i < list2.size(); i++) {
        cout << list1[i][0] << " " << list1[i][1] << " " << list2[i][0] << " " << list2[i][1] << endl;
    }
 
    return 0;
}