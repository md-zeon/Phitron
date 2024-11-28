#include <bits/stdc++.h>
using namespace std;

const int N = 1005; // Maximum number of nodes
vector<int> adjList[N];
bool visited[N];
vector<int> componentSizes;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int elements = 0; // Initialize size to 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        elements++; // Count the current node
        for (int v : adjList[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    if (elements > 1) { // Only consider components with more than one node
        componentSizes.push_back(elements);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Reading the graph
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Finding connected components
    for (int i = 0; i < N; i++) {
        if (!visited[i] && !adjList[i].empty()) { // Only visit valid nodes
            bfs(i);
        }
    }

    // Sorting component sizes
    sort(componentSizes.begin(), componentSizes.end());

    // Output the result
    for (int size : componentSizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
