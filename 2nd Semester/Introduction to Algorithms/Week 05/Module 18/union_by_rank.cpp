#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int nodeRank[1000];

void dsu_set(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
        nodeRank[i] = 0;
    }
}
int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB) {
        if (nodeRank[leaderA] > nodeRank[leaderB]) {
            parent[leaderB] = leaderA;
        } else if(nodeRank[leaderA] < nodeRank[leaderB]) {
            parent[leaderA] = leaderB;
        } else {
            parent[leaderB] = leaderA;
            nodeRank[leaderA]++;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--) {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }

    cout << dsu_find(5) << endl;
    

    return 0;
}