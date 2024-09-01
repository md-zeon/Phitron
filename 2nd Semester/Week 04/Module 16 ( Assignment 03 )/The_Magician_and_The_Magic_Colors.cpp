#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s) {
            if (st.empty()) {
                st.push(c);
            } else if(c == st.top()) {
                st.pop();
            } else if ((c == 'R' && st.top() == 'B') || (c == 'B' && st.top() == 'R')) {
                st.pop();
                st.push('P');
            } else if ((c == 'R' && st.top() == 'G') || (c == 'G' && st.top() == 'R')) {
                st.pop();
                st.push('Y');
            } else if ((c == 'B' && st.top() == 'G') || (c == 'G' && st.top() == 'B')) {
                st.pop();
                st.push('C');
            } else {
                st.push(c);
            }
        }

        stack<char> st2;
        while (!st.empty()) {
            if(st2.empty()) {
                st2.push(st.top());
            } else if (st2.top() == st.top()) {
                st2.pop();
            } else {
                st2.push(st.top());
            }

            st.pop();
        }

        s = "";
        while (!st2.empty()) {
            s += st2.top();
            st2.pop();
        }
        cout << s << endl;
    }


    return 0;
}