#include <bits/stdc++.h>
using namespace std;

// Bubble Sort

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool isSwapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }

        if(!isSwapped) {
            break;
        }
    }

}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++) {
        (i != n-1) ? cout << arr[i] << " " : cout << arr[i];
    }


    return 0;
}