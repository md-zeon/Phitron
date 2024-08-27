#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        int cls;
        char section;
        int id;
};

int main() {

    int n;
    cin >> n;
    Student s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].cls >> s[i].section >> s[i].id;
    }

    int i = 0, j = n-1;
    while (i < j) {
        swap(s[i].id, s[j].id);
        i++;
        j--;
    }

    for (int i = 0; i < n; i++) {
        cout << s[i].name << " " << s[i].cls << " " << s[i].section << " " << s[i].id << endl;
    }

    return 0;
}