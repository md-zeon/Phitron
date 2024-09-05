#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        int currIdx = v.size() - 1;

        while (currIdx != 0) {
            int parentIdx = (currIdx-1) / 2;
            if(v[parentIdx] > v[currIdx]) {
                swap(v[parentIdx], v[currIdx]);
            } else {
                break;
            }
            currIdx = parentIdx;
        }
    }

    
    for(int val : v) {
        cout << val << " ";
    }

    return 0;
}