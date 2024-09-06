#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        int maxVal = INT_MIN;
        int maxCount = 0;
        for (auto it : mp) {
            if (it.second > maxCount) {
                maxCount = it.second;
                maxVal = it.first;
            }
            if (it.second == maxCount) {
                if (it.first > maxVal) {
                    maxVal = it.first;
                }
            }
        }

        cout << maxVal << " " << maxCount << endl;
    }

    return 0;
}