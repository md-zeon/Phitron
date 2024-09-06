#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    // cout << v.max_size() << endl;

    // cout << v.capacity() << endl; // 0
    v.push_back(10);
    // cout << v.capacity() << endl; // 1
    v.push_back(20);
    // cout << v.capacity() << endl; // 2
    v.push_back(30);
    // cout << v.capacity() << endl; // 4
    v.push_back(40);
    // cout << v.capacity() << endl; // 4
    v.push_back(50);
    // cout << v.capacity() << endl; // 8

    cout << v.size() << endl;
    // v.clear();
    v.resize(2);
    v.resize(7, 100);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}