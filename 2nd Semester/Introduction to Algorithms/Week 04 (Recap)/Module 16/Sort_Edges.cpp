#include <bits/stdc++.h>
using namespace std;

int main() {
    int e;
    cin >> e;
    vector<pair<int, int>> edges;
    while (e--) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    sort(edges.begin(), edges.end());

    for (pair<int, int> edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }


    return 0;
}