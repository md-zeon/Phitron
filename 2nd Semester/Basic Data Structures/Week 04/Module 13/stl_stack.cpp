#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        s.push(data);
    }

    cout << "Size = " << s.size() << endl;

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    cout << "Size = " << s.size() << endl;

    return 0;
}