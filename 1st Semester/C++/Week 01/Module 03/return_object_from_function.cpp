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

Student fun() {
    char name[10] = "Rahim";
    Student s1(1, 2, 'A', name);
    return s1;
}

int main() {
    Student rahim = fun();

    cout << rahim.name << " " << rahim.roll << " " << rahim.cls << " " << rahim.section << endl;

    return 0;
}
