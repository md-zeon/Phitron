#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sp1 = 0;
    int sp2 = n-2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sp1; j++) {
            cout << " ";
        }
        if(i < (n/2)+1) {
            cout << "\\";
        } 
        
        if(i == (n/2)+1) {
            cout << "X";
        }
        
        if (i > n/2+1) {
            cout << "/";
        }

        for (int j = 1; j <= sp2; j++) {
            cout << " ";
        }

        if(i < (n/2)+1) {
            cout  << "/";
        }
        
        if (i > (n/2)+1) {
            cout << "\\";
        }

        cout << endl;

        if(i <= n / 2) {
            sp1++;
            sp2-=2;
        } else {
            sp1--;
            sp2+=2;
        }
    }


    return 0;
}