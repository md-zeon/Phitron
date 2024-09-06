#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> v;
public:
    void push(int val) {
        v.push_back(val);
    }
    void pop() {
        v.pop_back();
    }
    int top() {
        return v.back();
    }
    int size() {
        return v.size();
    }
    bool empty() {
        return v.empty();
    }
};

int main() {
    Stack s1, s2;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.push(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s2.push(x);
    }

    bool same = true;

    if(s1.size() != s2.size()) {
        same = false;
    } else {
        while(!s1.empty()) {
            if(s1.top() != s2.top()) {
                same = false;
                break;
            } else {
                s1.pop();
                s2.pop();
            }
        }
    }

    cout << (same ? "YES" : "NO") << endl;

    return 0;
}