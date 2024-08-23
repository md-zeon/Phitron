#include <iostream>
#include <algorithm> // for min and max
using namespace std;

int my_min(int a, int b) {
    return a < b ? a : b;
}

int my_max(int a, int b) {
    return a > b ? a : b;
}


int main() {

    int a, b;
    cin >> a >> b;

    // cout << my_min(a, b) << " " << my_max(a, b);
    cout << min(a, b) << " " << max(a, b);


    return 0;
}