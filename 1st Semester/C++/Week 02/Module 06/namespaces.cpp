#include <bits/stdc++.h>
using namespace std;

namespace Zeon {
    int age = 21;
    void hello() {
        cout << "Hello from Zeon Namespace" << endl;
    }

    class Z {
        public:
            void hello() {
                cout << "Hello from Z Class in Zeon Namespace" << endl;
            }
    };
}

using namespace Zeon;

int main() {

    // cout << Zeon::age << endl;
    cout << age << endl;

    // Zeon::hello();
    hello();

    // Zeon::Z z;
    Z z;
    z.hello();

    

    return 0;
}