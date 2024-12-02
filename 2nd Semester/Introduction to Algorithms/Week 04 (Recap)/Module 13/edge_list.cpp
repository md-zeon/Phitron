#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int,int>> edges;

    while (e--) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}