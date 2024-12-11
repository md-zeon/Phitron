#include <bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<int>> edges, vector<bool> &visited, int u, int parent) {
    visited[u] = true;

    for (int v : edges[u]) {
        if (!visited[v]) { // not visited
            if (hasCycle(edges, visited, v, u)) {
                return true;
            }
        } else if (v != parent) { // cycle exists
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> edges = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // vector<vector<int>> edges = {{}, {2}, {1, 3}, {2}};
    vector<bool> visited(edges.size(), false);

    if (hasCycle(edges, visited, 0, -1)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}