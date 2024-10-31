/************************************************************
*  Problem: Second Largest Element in the Array
*  Link   : https://www.naukri.com/code360/problems/second-largest-element-in-the-array_873375?leftPanelTab=0
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Find the second largest element in a given array. If the array 
*  has fewer than two unique elements, return -1 as there's no 
*  second largest element.

*  Approach:
*  - Initialize two variables, `first` and `second`, to track the 
*    largest and second-largest elements.
*  - Traverse through the array. For each element:
*     - If the element is greater than `first`, update `second` to 
*       `first`, and then set `first` to the current element.
*     - If the element is between `first` and `second`, update `second`.
*  - After the loop, `second` will contain the second largest element 
*    or remain -1 if no second largest element exists.

*  Time Complexity : O(n) - Single pass through the array.
*  Space Complexity: O(1) - Constant space usage.

*  Platform: Naukri Code360
*  Status  : [Solved/Unsolved]
************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN;

    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num < first) {
            second = num;
        }
    }

    return second == INT_MIN ? -1 : second;
}
