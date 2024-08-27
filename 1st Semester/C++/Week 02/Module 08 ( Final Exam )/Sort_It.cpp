#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        int cls;
        char section;
        int id;
        int mathMarks;
        int engMarks;
};

bool cmp(Student a, Student b) {
    if(a.mathMarks + a.engMarks > b.mathMarks + b.engMarks) {
        return true;
    } else if (a.mathMarks + a.engMarks == b.mathMarks + b.engMarks) {
        return a.id < b.id;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    Student s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].cls >> s[i].section >> s[i].id >> s[i].mathMarks >> s[i].engMarks;
    }

    sort(s, s+n, cmp);

    for (int i = 0; i < n; i++) {
        cout << s[i].name << " " << s[i].cls << " " << s[i].section << " " << s[i].id << " " << s[i].mathMarks << " " << s[i].engMarks << endl;
    }

    return 0;
}