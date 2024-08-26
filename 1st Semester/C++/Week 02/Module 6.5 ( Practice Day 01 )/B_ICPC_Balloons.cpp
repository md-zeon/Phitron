#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int freq[26] = {0};
        int balloons = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if(freq[s[i] - 'A'] == 0) {
                balloons += 2;
            } else {
                balloons += 1;
            }
            freq[s[i] - 'A']++;
        }

        cout << balloons << endl;
        
    }

    return 0;
}