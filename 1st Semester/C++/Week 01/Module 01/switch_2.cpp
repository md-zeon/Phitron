#include <iostream>

using namespace std;

int main() {
    char a;
    cin >> a;

    switch (a) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "Vowel";
            break;
        default:
            cout << "Consonant";
    }

    return 0;
}