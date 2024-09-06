#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    queue<int> q;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        s.push(x);
    }
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        q.push(x);
    }

    bool same = true;

    if (s.size() != q.size()) {
        same = false;
    } else {
        while (!s.empty()) {
            if (s.top() != q.front()) {
                same = false;
                break;
            } else {
                s.pop();
                q.pop();
            }
        }
    }

    cout << (same ? "YES" : "NO") << endl;

    return 0;
}