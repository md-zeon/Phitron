#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int sum = 0;
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            sum += (s[i] - '0');
            sum -= (s[j] - '0');
            i++;
            j--;
        }

        if (sum == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}