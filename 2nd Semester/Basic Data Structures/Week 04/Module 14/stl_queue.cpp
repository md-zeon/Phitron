#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Size: " << q.size() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}