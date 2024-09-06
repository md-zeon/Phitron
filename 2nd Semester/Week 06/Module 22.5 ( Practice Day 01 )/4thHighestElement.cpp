/************************************************************
*  Problem: 4th Highest Element
*  Link   : https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_1792782?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given an array of integers, find the 4th largest element in the array.
*
*  Approach:
*  - Use a max-heap to find the 4th largest element.
*  - Insert all elements of the array into a max-heap.
*  - Pop the top element of the heap 4 times, where the last popped element will be the 4th largest element.
*
*  Time Complexity : O(n log n)
*  - Building the max-heap takes O(n log n) since each insertion into the heap is O(log n).
*  Space Complexity: O(n)
*  - The space complexity is O(n) for storing the elements in the heap.
*  
*  Platform: Naukri Code360
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element into the max-heap
void insert_heap(vector<int> &v, int x) {
    v.push_back(x);  // Insert the new element at the end
    int currIdx = v.size() - 1;  // Get the index of the newly inserted element
    
    // Bubble up the element to maintain the max-heap property
    while (currIdx != 0) {
        int parentIdx = (currIdx - 1) / 2;  // Find the parent index
        if (v[parentIdx] < v[currIdx]) {  // If the parent is smaller, swap
            swap(v[parentIdx], v[currIdx]);
        } else {
            break;  // Stop if the heap property is restored
        }
        currIdx = parentIdx;  // Move to the parent index
    }
}

// Function to delete the root element (max element) from the max-heap
void deleteHeap(vector<int> &v) {
    // Swap the root with the last element and remove the last element
    swap(v[0], v[v.size() - 1]);
    v.pop_back();

    int currIdx = 0;  // Start at the root

    // Bubble down the element to maintain the max-heap property
    while (currIdx < v.size()) {
        int leftIdx = 2 * currIdx + 1;  // Left child index
        int rightIdx = 2 * currIdx + 2;  // Right child index
        int lastIdx = v.size() - 1;  // Index of the last element

        // Check if both children exist
        if (leftIdx <= lastIdx && rightIdx <= lastIdx) {
            // Compare the current node with its largest child
            if (v[currIdx] < max(v[leftIdx], v[rightIdx])) {
                // Swap with the larger child
                if (v[leftIdx] > v[rightIdx]) {
                    swap(v[currIdx], v[leftIdx]);
                    currIdx = leftIdx;
                } else {
                    swap(v[currIdx], v[rightIdx]);
                    currIdx = rightIdx;
                }
            } else {
                break;  // Stop if the heap property is restored
            }
        }
        // If only the left child exists
        else if (leftIdx <= lastIdx) {
            if (v[currIdx] < v[leftIdx]) {
                swap(v[currIdx], v[leftIdx]);
                currIdx = leftIdx;
            } else {
                break;
            }
        }
        // If only the right child exists
        else if (rightIdx <= lastIdx) {
            if (v[currIdx] < v[rightIdx]) {
                swap(v[currIdx], v[rightIdx]);
                currIdx = rightIdx;
            } else {
                break;
            }
        } else {
            break;  // No children, stop
        }
    }
}

// Function to get the 4th largest element in the array
int getFourthLargest(int arr[], int n) {
    vector<int> v;  // Vector to represent the max-heap

    // Insert all elements into the heap
    for (int i = 0; i < n; i++) {
        insert_heap(v, arr[i]);
    }

    // Pop the largest element from the heap 4 times to get the 4th largest element
    int place = 4;
    int max;
    while (place--) {
        if (!v.empty()) {
            max = v.front();  // Get the root element (maximum)
            deleteHeap(v);  // Remove the root element from the heap
        } else {
            return INT_MIN;  // If there are fewer than 4 elements, return INT_MIN
        }
    }

    return max;  // Return the 4th largest element
}
