#include <bits/stdc++.h>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    map<string, int> mp;
    while (ss >> word) {
        mp[word]++;
    }

    for (auto it : mp) {
        cout << it.first << " = " << it.second << endl;
    }

    return 0;
}