#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello World";
    cout << "Size: " << s.size() << endl;
    cout << "Max Size: " << s.max_size() << endl;
    cout << "Capacity: " << s.capacity() << endl;
    cout << s << endl;
    cout << "Empty: " << s.empty() << endl;
    s.clear();
    cout << s << endl;
    cout << "Empty: " << s.empty() << endl;

    s = "Hello World";
    cout << "Size: " << s.size() << endl;
    s.resize(15, 'X');
    cout << "Size: " << s.size() << endl;
    cout << s << endl;

    return 0;
}