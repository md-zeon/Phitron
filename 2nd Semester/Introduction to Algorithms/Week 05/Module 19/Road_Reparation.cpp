#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> pii;

vector<pii> adjList[N];
int visited[N];

class Edge {
    public:
        int u, v, w;
        Edge(int u, int v, int w) {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};

class cmp {
    public:
    bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};

pair<long long, int> prims(int s) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;
    long long totalCost = 0;
    int nodeCount = 0;

    while (!pq.empty()) {
        Edge parent = pq.top();
        pq.pop();
        if (visited[parent.v]) continue;
        visited[parent.v] = true;
        nodeCount++;
        totalCost += (long long)parent.w;
        edgeList.push_back(parent);
        for (pii child : adjList[parent.v]) {
            if (!visited[child.first]) {
                pq.push(Edge(parent.v, child.first, child.second));
            }
        }
    }
    return {totalCost, nodeCount};
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    pair<long long, int> ans = prims(1);

    if (ans.second == n) {
        cout << ans.first << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}