#include <iostream>
#include <vector>
using namespace std;
#define ll long long

const long long N = 2e5 + 5;

ll arr[N], b[N];

ll rec(ll arr[], ll target, ll sum, ll n, ll index);
int main()
{
    ll n, target; cin >> n >> target;
    for(ll i = 0; i < n; i++) cin >> arr[i];
    if (rec(arr, target, arr[0], n, 1) >= 1) cout << "YES";
    else cout << "NO";
    return 0;
}

ll rec(ll arr[], ll target, ll sum, ll n, ll index){
    if(index >= n && sum == target) return 1;
    if(index >= n && sum != target) return 0;
    
    return rec(arr, target, sum + arr[index], n, index + 1) + rec(arr, target, sum - arr[index], n, index + 1);
}


// #include <iostream>
// #include <vector>
// using namespace std;

// bool canFormExpression(const vector<int>& A, int index, long long currentSum, long long target) {
//     // Base case: if we processed all elements
//     if (index == A.size()) {
//         return currentSum == target;
//     }

//     // Recursively check by adding or subtracting the current element
//     return canFormExpression(A, index + 1, currentSum + A[index], target) ||
//            canFormExpression(A, index + 1, currentSum - A[index], target);
// }

// int main() {
//     int N;
//     long long X;
//     cin >> N >> X;

//     vector<int> A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }

//     if (canFormExpression(A, 0, 0, X)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }