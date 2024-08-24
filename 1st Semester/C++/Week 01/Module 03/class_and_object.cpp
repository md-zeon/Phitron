#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        char name[100];
        int roll;
        int cls;
        char section;
};

int main() {
    Student s1;
    s1.roll = 8;
    s1.cls = 10;
    s1.section = 'A';
    strcpy(s1.name, "Shakib Al hasan");

    Student s2;
    s2.roll = 9;
    s2.cls = 11;
    s2.section = 'B';
    strcpy(s2.name, "Tamim Iqbal");

    cout << s1.name << " " << s1.roll << " " << s1.cls << " " << s1.section << endl;
    cout << s2.name << " " << s2.roll << " " << s2.cls << " " << s2.section << endl;

    return 0;
}