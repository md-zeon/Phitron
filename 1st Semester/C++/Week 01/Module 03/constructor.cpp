#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        char name[100];
        int roll;
        int cls;
        char section;

        Student(int r, int c, char s, char n[]) {
            roll = r;
            cls = c;
            section = s;
            strcpy(name, n);
        }
};

int main() {

    Student s1(8, 10, 'A', "Shakib Al hasan");
    cout << s1.name << " " << s1.roll << " " << s1.cls << " " << s1.section << endl;

    Student s2(9, 11, 'B', "Tamim Iqbal");
    cout << s2.name << " " << s2.roll << " " << s2.cls << " " << s2.section << endl;

    return 0;
}
