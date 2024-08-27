#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = {101, 102, 103, 104};
    v.insert(v.begin() + 3, 100);
    v.insert(v.begin() + 4, v2.begin(), v2.end());

    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}