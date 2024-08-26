#include <bits/stdc++.h>
using namespace std;

void reverse_word(stringstream &ss) {
    string word;
    if(ss >> word) {
        reverse_word(ss);
        cout << word << " ";
    }
}

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    // string word;
    // while(ss >> word) {
    //     cout << word << endl;
    // }

    reverse_word(ss);


    return 0;
}