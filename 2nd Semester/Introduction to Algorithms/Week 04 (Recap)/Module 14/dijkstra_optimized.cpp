#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> adjList[N];
int dist[N];
bool visited[N];

void dijkstra_optimized(int s) { // O(n + e log n)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    

    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (visited[parentNode]) continue;
        visited[parentNode] = true;
        int parentCost = parent.first;
    
        for (pair<int, int> child : adjList[parentNode]) {
            int childNode = child.first;
            int childCost = child.second;
            if (parentCost + childCost < dist[childNode]) {
                dist[childNode] = parentCost + childCost;
                pq.push({dist[childNode], childNode});
            }
        }

    }
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

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dijkstra_optimized(1);

    for (int i = 1; i <= n; i++) {
        cout << "Distance of node " << i << " is: " << dist[i] << endl;
    }

    return 0;
}