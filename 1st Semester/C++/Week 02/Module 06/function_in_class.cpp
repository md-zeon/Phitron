#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        string name;
        int age;
        int mark1;
        int mark2;

        Person(string n, int a, int m1, int m2) {
            name = n;
            age = a;
            mark1 = m1;
            mark2 = m2;
        }

        void display() {
            cout << name << " " << age << endl;
        }

        int total_marks() {
            return mark1 + mark2;
        }
};

int main() {
    Person rakib("Rakib Ahsan", 24, 95, 85);

    rakib.display();
    cout << rakib.total_marks() << endl;

    return 0;
}