#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp.insert({"Sakib Al Hasan", 75});
    mp.insert({"Tamim Iqbal", 19});
    mp.insert({"Shamim", 79}); // O(log n)
    mp["Akib"] = 0; // O(log n)

    
    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << " " << it->second << endl; // O(log n)
    // }

    cout << mp["Shamim"] << endl; // 79
    cout << mp["Akib"] << endl; // 0
    cout << mp.count("Akib") << endl; // 1

    if(mp.count("Akib")) {
        cout << mp["Akib"] << endl;
    } else {
        cout << "Not found" << endl;
    }


    return 0;
}