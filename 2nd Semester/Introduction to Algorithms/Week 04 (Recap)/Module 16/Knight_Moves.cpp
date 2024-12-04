#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[101][101];
int steps[101][101];

vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true; 
    steps[si][sj] = 0; 

    while (!q.empty()) {
        pair<int, int> curr = q.front(); // current cell
        q.pop();
        int ci = curr.first; // current cell index in row
        int cj = curr.second; // current cell index in column

        // check all the possible moves from the current cell
        for (pair<int, int> &d : dir) {
            int di = ci + d.first; // destination index in row
            int dj = cj + d.second; // destination index in column

            // check if the destination is valid and not visited
            if (isValid(di, dj) && !visited[di][dj]) {
                q.push({di, dj});
                visited[di][dj] = true; // mark the destination as visited
                steps[di][dj] = steps[ci][cj] + 1; // update the steps for the destination
            }
        }
    }
}

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            steps[i][j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;
        bfs(ki, kj);
        if (visited[qi][qj]) {
            cout << steps[qi][qj] << endl;
        } else {
            cout << -1 << endl;
        }
        reset();
    }
    return 0;
}