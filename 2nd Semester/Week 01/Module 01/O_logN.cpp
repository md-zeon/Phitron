#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num = n;
    while (n != 0) { // O(log n)
        int digit = n % 10;
        cout << digit << " ";
        n = n / 10;
    }

    cout << endl;

    for (int i = 1; i <= num; i = i * 2) { // O(log n)
        cout << i << " ";
    }

    return 0;
}