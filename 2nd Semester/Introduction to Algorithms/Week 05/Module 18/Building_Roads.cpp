// #include <bits/stdc++.h>
// using namespace std;

// class DSU {
// private:
//     vector<int> parent, rank;

// public:
//     // Constructor: Initializes the DSU for n elements
//     DSU(int n) {
//         parent.resize(n+1);
//         rank.resize(n+1, 0);
//         for (int i = 0; i <= n; ++i) {
//             parent[i] = i; // Each node is its own parent initially
//         }
//     }

//     // Find function with path compression
//     int find(int x) {
//         if (parent[x] != x) {
//             parent[x] = find(parent[x]); // Path compression
//         }
//         return parent[x];
//     }

//     // Union function with union by rank
//     void union_sets(int x, int y) {
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

//     // Debug: Print the current parent and rank arrays
//     void print_debug() {
//         for (int i = 0; i < parent.size(); ++i) {
//             cout << "Parent[" << i << "] = " << parent[i] << endl;
//         }
//     }
// };

// int main() {
//     int n, e;
//     cin >> n >> e;
//     DSU dsu(n);

//     while (e--) {
//         int a, b;
//         cin >> a >> b;
//         dsu.union_sets(a, b);
//     }

//     map<int, bool> mp;

//     for (int i = 1; i <= n; i++) {
//         int leader = dsu.find(i);
//         mp[leader] = true;
//     }
    
//     vector<int> ans;
//     for (pair<int, bool> p : mp) {
//         ans.push_back(p.first);
//     }

//     cout << ans.size() - 1 << endl;

//     for (int i = 0; i < ans.size() - 1; i++) {
//         cout << ans[i] << " " << ans[i+1] << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int parentLevel[N];

void dsu_set(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
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
        if (parentLevel[leaderA] > parentLevel[leaderB]) {
            parent[leaderB] = leaderA;
        } else if (parentLevel[leaderA] < parentLevel[leaderB]) {
            parent[leaderA] = leaderB;
        } else {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--) {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    map<int, bool> mp;
    for (int i = 1; i <= n; i++) {
        int leader = dsu_find(i);
        mp[leader] = true;
    }

    vector<int> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->first);
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }

    return 0;
}