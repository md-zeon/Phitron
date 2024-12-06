#include <bits/stdc++.h>
using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

int main() {
    cout << find(6) << endl;

    return 0;
}