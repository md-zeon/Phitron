#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    getline(cin, s);
    bool inside_word = false;
    int count = 0;
    for (char c:s) {
        if(isalpha(c)) {
            if(!inside_word) {
                count++;
                inside_word = true;
            }
        } else {
            inside_word = false;
        }
    }

    cout << count;

    return 0;
}