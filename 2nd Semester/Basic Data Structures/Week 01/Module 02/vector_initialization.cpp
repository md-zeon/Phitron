#include <bits/stdc++.h>
using namespace std;

int main() {
    // type 1
    // vector<int> v;

    // type 2
    // vector<int> v(5);

    // type 3
    // vector<int> v(5, 10);

    // type 4
    // vector<int> v2(5, 100);
    // vector<int> v(v2);

    // type 5
    // int arr[5] = {1, 2, 3, 4, 5};
    // vector<int> v(arr, arr + 5);

    vector<int> v = {1, 2, 3, 4, 5};
    
    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;

    return 0;
}