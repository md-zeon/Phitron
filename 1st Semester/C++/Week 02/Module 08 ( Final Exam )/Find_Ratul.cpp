#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    bool found = false;
    while (ss >> word) {
        if (word == "Ratul") {
            found = true;
            break;
        }
    }

    cout << (found ? "YES\n" : "NO\n");
    

    return 0;
}