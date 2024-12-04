#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char graph[N][N];
bool visited[N][N];
int n, m;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int ci, int cj) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m;
}

void dfs(int si, int sj) {
    visited[si][sj] = true;

    for (int i = 0; i < dir.size(); i++) {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;

        if (isValid(ci, cj) && !visited[ci][cj] && graph[ci][cj] == '.') {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    
    dfs(si, sj);

    if (visited[di][dj]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}