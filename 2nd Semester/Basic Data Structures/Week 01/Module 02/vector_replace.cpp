#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 5, 4, 2, 5, 7, 3, 2, 3, 9, 2, 8};

    replace(v.begin(), v.end(), 2, 100);

    for (int i : v) {
        cout << i << " ";
    }


    return 0;
}