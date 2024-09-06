#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ll;
    int n;
    cin >> n;
    while (n != -1) {
        ll.push_back(n);
        cin >> n;
    }
    ll.sort();
    ll.unique();
    for (int i : ll) {
        cout << i << " ";
    }

    return 0;
}