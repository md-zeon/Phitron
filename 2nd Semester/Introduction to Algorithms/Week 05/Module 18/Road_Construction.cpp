// #include <bits/stdc++.h>
// using namespace std;

// class DSU {
// private:
//     vector<int> parent, rank, size;
//     int num_size;

// public:
//     // Constructor: Initializes the DSU for n elements
//     DSU(int n) {
//         parent.resize(n + 1);
//         rank.resize(n + 1, 0);
//         size.resize(n + 1, 1);
//         for (int i = 0; i <= n; ++i) {
//             parent[i] = i; // Each node is its own parent initially
//         }
//     }

//     // Find function with path compression
//     int find(int x) { // O(log n)
//         if (parent[x] != x) {
//             parent[x] = find(parent[x]); // Path compression
//         }
//         return parent[x];
//     }

//     // Union function with union by rank
//     void union_sets_by_rank(int x, int y) { // O(1)
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX != rootY) {
//             if (rank[rootX] < rank[rootY]) {
//                 parent[rootX] = rootY;
//             } else if (rank[rootX] > rank[rootY]) {
//                 parent[rootY] = rootX;
//             } else {
//                 parent[rootY] = rootX;
//                 rank[rootX]++;
//             }
//         }
//     }

//     // Union function with union by size
//     void union_sets_by_size(int x, int y) { // O(1)
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX != rootY) {
//             if (size[rootX] < size[rootY]) {
//                 parent[rootX] = rootY;
//                 size[rootY] += size[rootX];
//                 max_size = max(max_size, size[rootY]);
//             } else {
//                 parent[rootY] = rootX;
//                 size[rootX] += size[rootY];
//                 max_size = max(max_size, size[rootX]);
//             }
//         }
//     }

//     // Debug: Print the current parent and rank arrays
//     void print_debug() { // O(n)
//         for (int i = 0; i < parent.size(); ++i) {
//             cout << "Parent[" << i << "] = " << parent[i] << std::endl;
//         }
//     }

//     int get_max_size() { // O(1)
//         return max_size;
//     }
// };

// int main() {
//     int n, e;
//     cin >> n >> e;
//     DSU dsu(n);
//     int component_count = n;
//     for (int i = 0; i < e; ++i) {
//         int x, y;
//         cin >> x >> y;
//         dsu.union_sets_by_size(x, y);
//         component_count--;

//         cout << component_count << " " << dsu.get_max_size() << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N], ParentSize[N];
int max_size = 0;

void dsu_set(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
        ParentSize[i] = 1;
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
        if (ParentSize[leaderA] > ParentSize[leaderB]) {
            parent[leaderB] = leaderA;
            ParentSize[leaderA] += ParentSize[leaderB];
            max_size = max(max_size, ParentSize[leaderA]);
        } else {
            parent[leaderA] = leaderB;
            ParentSize[leaderB] += ParentSize[leaderA];
            max_size = max(max_size, ParentSize[leaderB]);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int cmp = n;
    while (e--) {
        int a, b;
        cin >> a >> b;
        if (dsu_find(a) != dsu_find(b)) {
            cmp--;
            dsu_union(a, b);
            cout << cmp << " " << max_size << endl;
        }
        
    }

    return 0;
}