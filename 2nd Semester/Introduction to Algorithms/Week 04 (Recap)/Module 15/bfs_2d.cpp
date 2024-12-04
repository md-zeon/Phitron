#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
bool visited[N][N];
int dist[N][N];
vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool isValid(int ci, int cj) {
    if (ci < 0 || cj < 0 || ci >= n || cj >= m) {
        return false;
    } else {
        return true;
    }
}

void bfs(int si, int sj) {
    queue<pii> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    visited[si][sj] = true;

    while (!q.empty()) {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            pii path = dir[i];
            int ci = pi + path.first;
            int cj = pj + path.second;

            if (isValid(ci, cj) && !visited[ci][cj]) {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dist[ci][cj] = dist[pi][pj] + 1;
            }

        }
    }

}

int main() {
    cin >> n >> m;
    char a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}