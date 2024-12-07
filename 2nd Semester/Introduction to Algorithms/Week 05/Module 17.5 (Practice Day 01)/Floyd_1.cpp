#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}