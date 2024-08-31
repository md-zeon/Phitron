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
    Stack s;
    // s.push(10);
    // s.push(20);
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.push(val);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}