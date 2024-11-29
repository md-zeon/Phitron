#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<string> g;
bool visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#') {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main() {
    int si, sj, di, dj;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        g.push_back(x);
        for (int j = 0; j < m; j++) {
            if (x[j] == 'A') {
                si = i;
                sj = j;
            }
            if (x[j] == 'B') {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    if (!visited[di][dj]) {  // Check if destination is visited
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << level[di][dj] << endl;

    vector<pair<int, int>> path;
    pair<int, int> curr = {di, dj};

    while (curr != make_pair(si, sj)) {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si, sj}); // source

    reverse(path.begin(), path.end());

    for (int i = 1; i < path.size(); i++) {
        if (path[i - 1].first == path[i].first) {
            if (path[i - 1].second < path[i].second) {
                cout << "R";
            } else {
                cout << "L";
            }
        } else {
            if (path[i - 1].first < path[i].first) {
                cout << "D";
            } else {
                cout << "U";
            }
        }
    }

    cout << endl;

    return 0;
}
