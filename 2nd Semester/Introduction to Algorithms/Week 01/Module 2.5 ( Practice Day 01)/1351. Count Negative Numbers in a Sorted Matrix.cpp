/************************************************************
*  Problem: 1351. Count Negative Numbers in a Sorted Matrix
*  Link   : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given an `n x m` matrix `grid` sorted in non-increasing order 
*  both row-wise and column-wise, return the number of negative numbers in `grid`.

*  Solution 1 - Brute-Force:
*  - Traverse each element in the grid.
*  - If the element is negative, increment the count.
*  
*  Time Complexity : O(n * m) – We examine every element in the grid.
*  Space Complexity: O(1) – Constant space for the counter variable.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int countNegative = 0; // Counter for negative numbers

        // Iterate through each row of the grid
        for (int i = 0; i < grid.size(); i++) {
            // Iterate through each element in the row
            for (int j = 0; j < grid[i].size(); j++) {
                // Check if the current element is negative
                if (grid[i][j] < 0) {
                    countNegative++; // Increment count if negative
                }
            }
        }
        
        return countNegative; // Return the total count of negative numbers
    }
};


/************************************************************
*  Problem: 1351. Count Negative Numbers in a Sorted Matrix
*  Link   : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given an `n x m` matrix `grid` sorted in non-increasing order 
*  both row-wise and column-wise, return the number of negative numbers in `grid`.

*  Solution 2 - Optimized Approach:
*  - Start from the top-right corner of the grid.
*  - Move left if the current element is negative (all elements below it are also negative).
*  - Move down if the current element is non-negative.
*  
*  Time Complexity : O(n + m) – Traverses at most one row and one column.
*  Space Complexity: O(1) – Constant space for the row, column, and counter variables.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

class Solution2 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int countNegative = 0; // Counter for negative numbers
        
        // Check if grid is empty to avoid errors
        if (grid.empty() || grid[0].empty()) return countNegative;

        int row = 0;               // Start at the first row
        int col = grid[0].size() - 1; // Start at the last column

        // Loop until we are out of bounds in rows or columns
        while (row < grid.size() && col >= 0) {
            // If the current element is negative
            if (grid[row][col] < 0) {
                // All elements below in this column are also negative
                countNegative += grid.size() - row; // Add count of negatives in this column
                col--; // Move left to check the next column
            } else {
                row++; // Move down to the next row if the element is non-negative
            }
        }
        
        return countNegative; // Return the total count of negative numbers
    }
};
