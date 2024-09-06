#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int x) {
    v.push_back(x);
    int currIdx = v.size() - 1;
    while (currIdx != 0) {
        int parentIdx = (currIdx-1) / 2;
        if(v[parentIdx] < v[currIdx]) {
            swap(v[parentIdx], v[currIdx]);
        } else {
            break;
        }
        currIdx = parentIdx;
    }
}

void deleteHeap(vector<int> &v) {
    swap(v[0], v[v.size() - 1]);
    v.pop_back();

    int currIdx = 0;

    while (currIdx < v.size()) {
        int leftIdx = 2 * currIdx + 1;
        int rightIdx = 2 * currIdx + 2;
        int lastIdx = v.size() - 1;

        if (leftIdx <= lastIdx && rightIdx <= lastIdx) {
            // duitai ase
            if (v[currIdx] < max(v[leftIdx], v[rightIdx])) {
                if (v[leftIdx] > v[rightIdx]) {
                    swap(v[currIdx], v[leftIdx]);
                    currIdx = leftIdx;
                } else {
                    swap(v[currIdx], v[rightIdx]);
                    currIdx = rightIdx;
                }
            } else {
                break;
            }
        } else if (leftIdx <= lastIdx) {
            // left ase
            if (v[currIdx] < v[leftIdx]) {
                swap(v[currIdx], v[leftIdx]);
                currIdx = leftIdx;
            } else {
                break;
            }
        } else if (rightIdx <= lastIdx) {
            // right ase
            if (v[currIdx] < v[rightIdx]) {
                swap(v[currIdx], v[rightIdx]);
                currIdx = rightIdx;
            } else {
                // kono tai nai
                break;
            }
        } else {
            break;
        }
    }
}

void printHeap(vector<int> v) {
    for(int val : v) {
        cout << val << " ";
    }
} 

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert_heap(v, x);
    }

    printHeap(v);
    deleteHeap(v);
    cout << endl;
    printHeap(v);
    deleteHeap(v);
    cout << endl;
    printHeap(v);
    

    return 0;
}