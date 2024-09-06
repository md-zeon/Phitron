#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    list<int> ll;

public:
    void push(int val) {
        ll.push_back(val);
    }

    void pop() {
        ll.pop_front();
    }

    int front() {
        return ll.front();
    }

    int size() {
        return ll.size();
    }

    bool empty() {
        return ll.empty();
    }
};

int main() {
    Queue q;
    int n;
    cin >> n;
    while (n--) {
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