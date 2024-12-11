#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        if (n % 2 == 0 || n > 6) {
            (n - 2 == 0) ? cout << s.substr(i, 2) : cout << s.substr(i, 2) << "-";
            i++;
            n -= 2;
        } else {
            (n - 3 == 0) ? cout << s.substr(i, 3) : cout << s.substr(i, 3) << "-";
            i += 2;
            n -= 3;
        }
    }

    return 0;
}