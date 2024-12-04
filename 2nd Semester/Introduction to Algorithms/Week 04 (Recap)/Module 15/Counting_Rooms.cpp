#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e3 + 5;
char arr[N][N];
bool visited[N][N];
typedef pair<int, int> pii;
vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int ci, int cj) {
    if (ci < 0 || cj < 0 || ci >= n || cj >= m || arr[ci][cj] == '#') {
        return false;    
    } else {
        return true;
    }
}


void dfs(int si, int sj) {
    visited[si][sj] = true;

    for (int i = 0; i < dir.size(); i++) {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;

        if (isValid(ci, cj) && !visited[ci][cj] && arr[ci][cj] == '.') {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0;  j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == '.') {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}