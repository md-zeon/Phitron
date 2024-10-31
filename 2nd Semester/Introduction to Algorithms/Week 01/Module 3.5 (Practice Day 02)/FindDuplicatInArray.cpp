/************************************************************
*  Problem: Find Duplicate in Array
*  Link   : https://www.naukri.com/code360/problems/find-duplicate-in-array_1112602?leftPanelTab=0&leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given an array of integers `arr` of size `n`, where each integer is 
*  in the range from 1 to n, find the duplicate number in the array. 
*  It is guaranteed that at least one duplicate number exists.
*  
*  Example:
*    Input: arr = [1, 3, 4, 2, 2]
*    Output: 2
*  
*  Approach:
*  - Use a hash map to keep track of the count of each element.
*  - Traverse the array and for each element, check if it is already in 
*    the hash map.
*  - If it is found, return that element as it is the duplicate.
*  - If it is not found, add it to the hash map.
*  
*  Time Complexity : O(n) – we traverse the array once.
*  Space Complexity: O(n) – for storing elements in the hash map.
*  
*  Platform: Naukri
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Function to find the duplicate in the array
int findDuplicate(vector<int> &arr, int n) {
    unordered_map<int, int> hash; // Hash map to store counts of elements
    for (int i = 0; i < n; i++) { // Traverse the array
        // Check if the element has already been seen
        if (hash[arr[i]] == 0) { // If not seen, mark it as seen
            hash[arr[i]] = 1;
        } else {
            return arr[i]; // If seen, it's the duplicate; return it
        }
    }
    return -1; // Return -1 if no duplicate is found (though guaranteed)
}
