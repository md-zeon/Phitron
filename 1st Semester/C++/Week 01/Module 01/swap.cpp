#include <iostream>
#include <utility> // for swap

void my_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // my_swap(&a, &b);

    swap(a, b);

    cout << a << " " << b;


}