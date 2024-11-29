#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

vector<string> g;
bool visited[N][N];
int n, m;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    if (g[i][j] == '#') return;
    if (visited[i][j]) return;
    if (!isValid(i, j)) return;

    visited[i][j] = true;
    
    // dfs(i - 1, j); // up
    // dfs(i + 1, j); // down
    // dfs(i, j - 1); // left
    // dfs(i, j + 1); // right

    for (auto d : dir) {
        int x = i + d.first;
        int y = j + d.second;
        dfs(x, y);
    }
}

int main() {
    // int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        g.push_back(x);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') continue;
            if (visited[i][j]) continue;
            dfs(i, j);
            cnt++;
        } 
    }

    cout << cnt << endl;

    return 0;
}