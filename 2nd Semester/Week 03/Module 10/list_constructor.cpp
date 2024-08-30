#include <bits/stdc++.h>
using namespace std;

int main() {
    // type 01
    // list<int> myList;

    //type 02
    // list<int> myList(5);

    // type 03
    // list<int> myList(5, 10);

    // type 04
    // list<int> list2 = {1, 2, 3, 4, 5};
    // list<int> myList(list2);

    // type 05
    // int a[5] = {10, 20, 30, 40, 50};
    // list<int> myList(a, a + 5);

    // type 06
    vector<int> v = {100, 200, 300, 400, 500};
    list<int> myList(v.begin(), v.end());


    cout << myList.size() << endl;

    // for (auto it = myList.begin(); it != myList.end(); it++) {
    //     cout << *it << " -> ";
    // }

    for (int val : myList) {
        cout << val << " -> ";
    }

    cout << "NULL" << endl;

    return 0;
}