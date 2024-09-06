#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    stack<int> s;
    while (n--) {
        int x;
        cin >> x;
        s.push(x);
    }

    queue<int> q;
    while (m--) {
        int x;
        cin >> x;
        q.push(x);
    }

    bool same = true;

    if(s.size() != q.size()) {
        same = false;
    } else {
        while (!s.empty()) {
            if (s.top() != q.front()) {
                same = false;
                break;
            }
            s.pop();
            q.pop();
        }
    }

    cout << (same ? "YES" : "NO") << endl;

    return 0;
}