#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s; // BST
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x); // O(log n) //! Removes Duplicate
    }
    cout << "Size = " << s.size() << endl;

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    cout << s.count(100) << endl; // O(log n)

    if (s.count(1000)) { // O(log n)
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    //! NOTE: set Removes Duplicate

    return 0;
}