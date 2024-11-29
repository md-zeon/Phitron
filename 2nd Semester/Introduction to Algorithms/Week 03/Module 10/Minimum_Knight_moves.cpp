#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool visited[N][N];
int level[N][N];
vector<pair<int, int>> dir = {
                                {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
                             };
int n;

bool isValid(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
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

            if (isValid(ni, nj) && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}

void resetLevelVisited() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';

        bfs(si, sj);

        cout << level[di][dj] << endl;
        resetLevelVisited();
    }

    return 0;
}
