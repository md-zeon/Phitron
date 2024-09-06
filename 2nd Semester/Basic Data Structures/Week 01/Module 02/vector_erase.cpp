#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    v.erase(v.begin() + 3); // deletes 4

    v.erase(v.begin() + 1, v.begin() + 3); // deletes 2, 3

    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}