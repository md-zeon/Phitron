/************************************************************
*  Problem: Merge Sort
*  Link   : https://www.naukri.com/code360/problems/merge-sort_920442?leftPanelTab=0&leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given an unsorted array, sort it using the Merge Sort algorithm.
*  Merge Sort is a divide-and-conquer algorithm that divides the array 
*  into halves, recursively sorts each half, and then merges the sorted 
*  halves to produce a sorted array.

*  Approach:
*  1. Split the array recursively into two halves until each subarray 
*     contains a single element or is empty.
*  2. Use a `merge` function to combine sorted subarrays into a single 
*     sorted array.
*  3. Continue merging sorted subarrays until the entire array is sorted.

*  Time Complexity : O(n log n) - Each level of recursion processes 
*                    the array in linear time, and there are log(n) 
*                    levels due to the division.
*  Space Complexity: O(n) - Temporary storage in the `merge` function 
*                    requires additional space proportional to the 
*                    size of the array.
*  
*  Platform: Naukri Code360
*  Status  : Solved
************************************************************/



#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int si, int mid, int ei) {
    int i = si;  // Starting index for the left sub array
    int j = mid + 1;  // Starting index for the right sub array
    vector<int> temp;

    // Merge elements from both halves into temp
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy any remaining elements from the right half
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy merged elements back into the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[si + k] = temp[k];
    }
}

void mergeSortHelper(vector<int> &arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSortHelper(arr, si, mid);
    mergeSortHelper(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

void mergeSort(vector<int> &arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}