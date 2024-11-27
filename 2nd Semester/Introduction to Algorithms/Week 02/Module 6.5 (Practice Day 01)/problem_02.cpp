#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int adjMatrix[n][n];

    // Input the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // Convert to adjacency list
    vector<int> adjList[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "List " << i + 1 << ": ";
        for (int j : adjList[i]) {
            cout << j + 1 << " "; // Convert back to 1-based indexing for output
        }
        cout << endl;
    }

    return 0;
}
