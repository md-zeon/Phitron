#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> myList = {10, 20, 30, 40, 50};

    // Assign function

    // list<int> newList;
    // newList = myList;
    // newList.assign(myList.begin(), myList.end());
    // for (int val : newList) {
    //     cout << val << " -> ";
    // }
    // cout << "NULL" << endl;

    
    // myList.push_back(100);
    // myList.push_front(200);
    // for (int val : myList) {
    //     cout << val << " -> ";
    // }
    // cout << "NULL" << endl;


    // myList.pop_back();
    // for (int val : myList) {
    //     cout << val << " -> ";
    // }
    // cout << "NULL" << endl;


    // myList.pop_front();
    // for (int val : myList) {
    //     cout << val << " -> ";
    // }
    // cout << "NULL" << endl;


    // insert
    // list<int> newList = {100, 200, 300};
    // vector<int> v = {60, 70, 80};
    // myList.insert(next(myList.begin(), 2), 100);
    // myList.insert(next(myList.begin(), 2), {100, 200, 300});
    // myList.insert(next(myList.begin(), 2), newList.begin(), newList.end());
    // myList.insert(next(myList.begin(), myList.size()), v.begin(), v.end());

    // erase

    // myList.erase(next(myList.begin(), 2));
    // myList.erase(next(myList.begin(), 2), next(myList.begin(), 5));

    // replace
    // myList.push_back(30);
    // myList.insert(next(myList.begin(), 3), 30);
    // myList.push_front(30);

    // replace(myList.begin(), myList.end(), 30, 150);


    // for (int val : myList) {
    //     cout << val << " -> ";
    // }
    // cout << "NULL" << endl;

    // find

    auto it = find(myList.begin(), myList.end(), 70);

    if (it != myList.end()) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }


    return 0;
}