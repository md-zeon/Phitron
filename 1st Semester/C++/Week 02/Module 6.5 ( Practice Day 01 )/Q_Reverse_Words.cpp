#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;

    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }
    ss.clear();
    ss << s;
    for(int i = 0; i < count; i++) {
        ss >> word;
        reverse(word.begin(), word.end());
        (i == count-1) ? cout << word : cout << word << " ";
    }

    return 0;
}