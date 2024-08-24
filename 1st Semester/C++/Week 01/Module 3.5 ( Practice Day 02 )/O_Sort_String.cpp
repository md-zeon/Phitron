#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // int freq[26] = {0};

    // for (int i = 0; i < n; i++) {
    //     char s;
    //     cin >> s;
    //     freq[s - 'a']++;
    // }

    // for (int i = 0; i < 26; i++) {
    //     for(int j = 0; j < freq[i]; j++) {
    //         cout << char(i + 'a');
    //     }
    // }

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    cout << s;
    return 0;
}