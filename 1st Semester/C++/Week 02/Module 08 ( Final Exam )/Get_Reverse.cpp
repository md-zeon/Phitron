#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        int cls;
        char section;
        int mathMarks;
        int engMarks;
};

int main() {
    int n;
    cin >> n;

    Student s[n];

    for(int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].cls >> s[i].section >> s[i].mathMarks >> s[i].engMarks;
    }
    
    reverse(s, s+n);

    for(int i = 0; i < n; i++) {
        cout << s[i].name << " " << s[i].cls << " " << s[i].section << " " << s[i].mathMarks << " " << s[i].engMarks << endl;
    }


    return 0;
}