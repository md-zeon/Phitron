#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int lli;
const int N = 1e6 + 5;
vector<pii> adjList[N];
vector<lli> dist(N, INT_MAX);
vector<bool> visited(N, false);

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        pii upair = pq.top();
        pq.pop();
        int u = upair.second;
        if (visited[u]) continue;
        visited[u] = true;

        for (pii vpair : adjList[u]) {
            int v = vpair.first;
            int w = vpair.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    lli n, e;
    cin >> n >> e;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    lli source;
    cin >> source;
    lli t;
    cin >> t;
    dijkstra(source);

    while (t--) {
        int destination, weight;
        cin >> destination >> weight;

        if (dist[destination] == INT_MAX) {
            cout << "NO" << endl;  
        } else if (dist[destination] <= weight) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    

    return 0;
}