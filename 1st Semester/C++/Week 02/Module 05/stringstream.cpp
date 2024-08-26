#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << s << endl;

    // stringstream ss;
    // ss << s;
    stringstream ss(s);

    string word;

    while (ss >> word) {
        cout << word << endl;
    }

    cout << s << endl;

    // cout << ss.str() << endl;

    return 0;
}