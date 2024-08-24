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
    char name[10] = "Rahim";
    // dynamic object create 
    Student* rahim = new Student(10, 12, 'A', name);
    // cout << "Name: " << (*rahim).name << endl;
    cout << "Name: " << rahim->name << endl;
    cout << "Class: " << rahim->cls << endl;
    cout << "Section: " << rahim->section << endl;
    cout << "Roll: " << rahim->roll << endl;


    // delete an object
    delete rahim;

    return 0;
}
