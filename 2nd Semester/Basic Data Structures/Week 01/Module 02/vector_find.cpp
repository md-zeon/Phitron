#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 5, 4, 2, 5, 7, 3, 2, 3, 9, 2, 8};

    auto it = find(v.begin(), v.end(), 7);
    
    if (it != v.end()) {
        cout << "Element found at position: " << it - v.begin() << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}