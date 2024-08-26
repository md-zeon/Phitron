#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        int roll;
        int marks;
};

bool cmp(Student a, Student b) {
    return a.marks < b.marks;
}

int main() {
    Student a[3];

    for(int i = 0; i < 3; i++) {
        getline(cin, a[i].name);
        cin >> a[i].roll >> a[i].marks;
        cin.ignore();
    }
    // ascending order
    // sort(a, a + 3, cmp);
    // descending order
    sort(a, a + 3, [](Student a, Student b) {
        return a.marks > b.marks;
    });

    for(int i = 0; i < 3; i++) {
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }
    

    return 0;
}