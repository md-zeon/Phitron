/************************************************************
*  Problem: 695. Max Area of Island
*  Link   : https://leetcode.com/problems/max-area-of-island/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-04
*  ----------------------------------------------
*  Problem Description:
*  Given a binary 2D grid where `1` represents land and `0` represents water,
*  find the maximum area of any connected "island." An island is formed by
*  connecting horizontally or vertically adjacent `1`s.
*
*  Approach:
*  - Use Depth-First Search (DFS) to explore each connected island.
*  - Traverse the grid, and for each unvisited cell with a value of `1`:
*      * Perform DFS to compute the size of the island.
*      * Update the maximum island size found so far.
*  - Mark visited cells to avoid redundant computation.
*
*  Time Complexity : O(N * M) - Each cell is visited at most once.
*  Space Complexity: O(N * M) - For the visited array and DFS stack.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Grid dimensions
    int n, m;
    
    // Directions for moving up, down, left, and right
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Visited array to keep track of explored cells
    bool visited[51][51];
    
    // Utility function to check if a cell is valid
    bool isValid(int ci, int cj) {
        return ci >= 0 && cj >= 0 && ci < n && cj < m;
    }
    
    // Recursive DFS to compute the size of an island
    void dfs(vector<vector<int>>& grid, int si, int sj, int& cnt) {
        visited[si][sj] = true; // Mark the cell as visited
        cnt++; // Increment the island size

        // Explore all 4 neighboring cells
        for (auto [dx, dy] : dir) {
            int ci = si + dx;
            int cj = sj + dy;

            // Continue DFS if the cell is valid, unvisited, and part of the island
            if (isValid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == 1) {
                dfs(grid, ci, cj, cnt);
            }
        }
    }

public:
    // Main function to find the maximum area of an island
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();          // Number of rows
        m = grid[0].size();       // Number of columns

        int maxCnt = 0;           // Maximum island size found so far

        // Initialize visited array to false
        memset(visited, false, sizeof(visited));

        // Traverse each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is land and unvisited, explore it
                if (!visited[i][j] && grid[i][j] == 1) {
                    int cnt = 0; // Size of the current island
                    dfs(grid, i, j, cnt); // Perform DFS to compute its size
                    maxCnt = max(maxCnt, cnt); // Update maximum size
                }
            }
        }

        return maxCnt; // Return the maximum island size
    }
};
