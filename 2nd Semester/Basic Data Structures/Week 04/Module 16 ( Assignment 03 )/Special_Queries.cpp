#include <bits/stdc++.h>
using namespace std;

int main() {
    int qr;
    cin >> qr;
    queue<string> q;
    while (qr--) {
        int n;
        cin >> n;
        if(n == 0) {
            string s;
            cin >> s;
            q.push(s);
        } else {
            if(q.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }

    return 0;
}