#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "Hello";
    string b = "World";
    // a = a+b;
    a.append(b);
    cout << a << endl;

    a = "HelloA";
    a.push_back('A');
    cout << a << endl;

    a.pop_back();
    cout << a << endl;

    // a = "Hello World";
    a.assign("Hello World");
    cout << a << endl;

    a.erase(4, 1);
    cout << a << endl;
    a.replace(4, 0, "o");
    cout << a << endl;
    a.insert(5, " Zeon");
    cout << a << endl;

    return 0;
}