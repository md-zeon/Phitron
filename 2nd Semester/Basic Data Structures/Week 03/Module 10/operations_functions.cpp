#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> myList = {30, 40, 10, 30, 50, 10, 10};

    // myList.remove(10); // removes all 10 from the list

    myList.sort(); // ascending order
    // myList.sort(greater<int>()); // descending order

    // myList.unique(); // value must be sorted

    myList.reverse();


    for (int val : myList) {
        cout << val << " -> ";
    }
    cout << "NULL" << endl;

    return 0;
}