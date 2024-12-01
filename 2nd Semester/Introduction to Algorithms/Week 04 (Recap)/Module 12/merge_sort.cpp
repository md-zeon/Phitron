#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int L[leftSize];
    int R[rightSize];

    int k = 0;
    for (int i = l; i <= m; i++) {
        L[k] = arr[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++) {
        R[k] = arr[i];
        k++;
    }
    int i = 0, j = 0;
    k = l;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        cout << "Merging:\n";
        for (int i = l; i <= mid; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = mid + 1; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        merge(arr, l, mid, r);
        cout << "Merged:\n";
        for (int i = l; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i <n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;



    return 0;
}