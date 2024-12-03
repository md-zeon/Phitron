#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> adjList[N];
int dist[N];

void dijkstra_naive(int source) { // O(n^2)
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < adjList[parent].size(); i++) {
            pair<int, int> child = adjList[parent][i];
            int childNode = child.first;
            int childCost = child.second;

            if (dist[parent] + childCost < dist[childNode]) {
                dist[childNode] = dist[parent] + childCost;
                q.push(childNode);
            }
        }
    }

}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dijkstra_naive(1);

    for(int i = 1; i <= n; i++) {
        cout << "Distance of node " << i << " is: " << dist[i] << endl;
    }

    return 0;
}