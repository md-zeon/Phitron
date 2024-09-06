/************************************************************
*  Problem: 1464. Maximum Product of Two Elements in an Array
*  Link   : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the array of integers `nums`, you will choose two different indices i and j of that array.
*    Return the maximum value of (nums[i]-1)*(nums[j]-1).
*
*  Approach:
*  - This solution uses a max heap to find the two largest elements in the array.
*  - Insert all elements of the array into a max heap.
*  - Extract the two largest elements from the heap and calculate the product `(max1-1) * (max2-1)`.
*
*  Time Complexity : O(n log n)
*  - Inserting each element into the heap takes O(log n) time, so for n elements, it takes O(n log n).
*
*  Space Complexity: O(n)
*  - The heap stores n elements, so the space complexity is O(n).
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Insert an element into the max heap
    void insertHeap(vector<int> &v, int x) {
        // Step 1: Insert the new element `x` at the end of the vector `v`
        v.push_back(x); 
        int currIdx = v.size() - 1; // The index of the newly inserted element
        
        // Step 2: "Heapify up" to maintain the max-heap property
        // Keep comparing the inserted element with its parent and swapping if necessary
        while (currIdx != 0) {
            int parentIdx = (currIdx - 1) / 2; // Calculate the parent index
            if (v[currIdx] > v[parentIdx]) {   // If the current element is larger than the parent
                swap(v[currIdx], v[parentIdx]); // Swap the elements
            } else {
                break;  // If the heap property is satisfied, stop
            }
            currIdx = parentIdx; // Move to the parent's index and continue heapifying up
        }
    }

    // Delete the root element (maximum) from the max heap
    void deleteHeap(vector<int> &v) {
        if (v.size() == 0) return; // If the heap is empty, nothing to delete

        // Step 1: Replace the root (maximum element) with the last element in the heap
        v[0] = v[v.size() - 1]; 
        v.pop_back();  // Remove the last element (now at the root)

        int currIdx = 0; // Start heapifying down from the root

        // Step 2: "Heapify down" to restore the max-heap property
        while (currIdx < v.size()) {
            int leftIdx = (currIdx * 2) + 1;  // Index of the left child
            int rightIdx = (currIdx * 2) + 2; // Index of the right child
            int lastIdx = v.size() - 1;       // Last index of the heap

            // If both left and right children exist
            if (leftIdx <= lastIdx && rightIdx <= lastIdx) {
                // Find the larger child and swap with the current node if necessary
                if (v[currIdx] < max(v[leftIdx], v[rightIdx])) {
                    if (v[leftIdx] >= v[rightIdx]) {
                        swap(v[currIdx], v[leftIdx]); // Swap with the left child if it is larger
                        currIdx = leftIdx;  // Move to the left child index and continue heapifying down
                    } else {
                        swap(v[currIdx], v[rightIdx]); // Swap with the right child if it is larger
                        currIdx = rightIdx; // Move to the right child index and continue heapifying down
                    }
                } else {
                    break; // If the current node is larger than both children, stop
                }
            }
            // If only the left child exists
            else if (leftIdx <= lastIdx) {
                if (v[leftIdx] > v[currIdx]) { // Swap if the left child is larger
                    swap(v[currIdx], v[leftIdx]);
                    currIdx = leftIdx; // Move to the left child index
                } else {
                    break; // Stop if the heap property is satisfied
                }
            }
            // If only the right child exists
            else if (rightIdx <= lastIdx) {
                if (v[rightIdx] > v[currIdx]) { // Swap if the right child is larger
                    swap(v[currIdx], v[rightIdx]);
                    currIdx = rightIdx; // Move to the right child index
                } else {
                    break; // Stop if the heap property is satisfied
                }
            } else {
                break; // If no children exist, stop
            }
        }
    }

    // Function to find the maximum product of two elements in the array
    int maxProduct(vector<int>& nums) {
        vector<int> maxHeap; // Create a max heap (represented as a vector)

        // Step 1: Insert all elements from the array `nums` into the max heap
        for (int i = 0; i < nums.size(); i++) {
            insertHeap(maxHeap, nums[i]); // Insert element into the heap
        }

        // Step 2: Extract the largest element from the heap and decrement by 1
        int max1 = maxHeap.front() - 1; // The largest element minus 1
        deleteHeap(maxHeap);  // Remove the largest element from the heap

        // Step 3: Extract the second largest element from the heap and decrement by 1
        int max2 = maxHeap.front() - 1; // The second largest element minus 1

        // Step 4: Return the product of the two largest elements (after decrementing by 1)
        return max1 * max2;
    }
};
