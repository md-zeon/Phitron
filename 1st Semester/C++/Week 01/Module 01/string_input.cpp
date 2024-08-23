#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[100];
    // cin >> a;
    cin.getline(a, 100);
    cout << a << endl;
    cout << strlen(a) << endl;

    return 0;
}
