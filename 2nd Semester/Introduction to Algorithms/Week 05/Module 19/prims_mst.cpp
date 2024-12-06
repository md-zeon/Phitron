#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> pii;

vector<pii> adjList[N];
bool visited[N];

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

void primsMST(int source) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(source, source, 0));
    vector<Edge> mst;

    while (!pq.empty()) {
        Edge parent = pq.top();
        pq.pop();

        int a = parent.u;
        int b = parent.v;
        int w = parent.w;

        if (visited[b] == true) continue;
        visited[b] = true;
        mst.push_back(parent);
        
        for (int i = 0; i < adjList[b].size(); i++) {
            pii child = adjList[b][i];
            if (!visited[child.first]) {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }

    mst.erase(mst.begin());
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.w << endl;
    }
}

int main() {
    int n , e;
    cin >> n >> e;

    while (e--) {
        int u , v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    primsMST(1);

    return 0;
}