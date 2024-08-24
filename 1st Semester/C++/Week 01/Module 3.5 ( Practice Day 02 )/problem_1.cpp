#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        char name[30];
        int roll;
        char section;
        float math_marks;
        int cls;
        Student(char name[], int roll, char section, float math_marks, int cls) {
            strcpy(this->name, name);
            this->roll = roll;
            this->section = section;
            this->math_marks = math_marks;
            this->cls = cls;
        }
};


int main() {
    //Then compare 3 objects and print who got the highest math_marks and print his/her name.

    // obj 1
    char n1[] = "Rohan";
    Student s1(n1, 1, 'A', 85.5, 12);

    // obj 2
    char n2[] = "Sohan";
    Student s2(n2, 2, 'B', 75.5, 11);

    // obj 3
    char n3[] = "Karan";
    Student s3(n3, 3, 'C', 95.5, 10);

    if(s1.math_marks > s2.math_marks && s1.math_marks > s3.math_marks) {
        cout << s1.name << " got the highest marks" << endl;
    } else if(s2.math_marks > s1.math_marks && s2.math_marks > s3.math_marks) {
        cout << s2.name << " got the highest marks" << endl;
    } else if(s3.math_marks > s1.math_marks && s3.math_marks > s2.math_marks) {
        cout << s3.name << " got the highest marks" << endl;
    }


    return 0;
}