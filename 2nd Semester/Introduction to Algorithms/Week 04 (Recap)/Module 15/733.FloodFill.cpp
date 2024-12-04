/************************************************************
*  Problem: 733. Flood Fill
*  Link   : https://leetcode.com/problems/flood-fill/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-04
*  ----------------------------------------------
*  Problem Description:
*  Given a 2D grid (image) where each cell has an integer value
*  representing a color, you need to perform a "flood fill."
*  Starting from a given pixel (sr, sc), change all connected
*  pixels of the same color to a new color.

*  Approach:
*  - Use Depth-First Search (DFS) to traverse all connected
*    pixels starting from the source pixel.
*  - Maintain a visited array to avoid reprocessing pixels.
*  - Change the color of connected pixels during the traversal.

*  Time Complexity : O(N * M) - Each pixel is visited once.
*  Space Complexity: O(N * M) - For recursion stack and visited array.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Visited array to keep track of processed pixels
    bool visited[51][51]; 

    // Directions for moving up, down, left, and right
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 

    // Dimensions of the grid
    int n, m; 

    // Helper function to check if a cell is valid (within bounds)
    bool isValid(int ci, int cj) {
        return ci >= 0 && cj >= 0 && ci < n && cj < m;
    }

    // Depth-First Search function for flood fill
    void dfs(vector<vector<int>>& image, int si, int sj, int scolor, int clr) {
        // Mark the current cell as visited
        visited[si][sj] = true;

        // Change the color if it matches the source color
        if (image[si][sj] == scolor) {
            image[si][sj] = clr;
        }

        // Process all four neighboring cells
        for (int i = 0; i < dir.size(); i++) {
            int ci = si + dir[i].first;
            int cj = sj + dir[i].second;

            // Recur for valid, unvisited, and same-color neighbors
            if (isValid(ci, cj) && !visited[ci][cj] && image[ci][cj] == scolor) {
                dfs(image, ci, cj, scolor, clr);
            }
        }
    }

public:
    // Main function to perform the flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();          // Number of rows
        m = image[0].size();       // Number of columns

        // Start DFS from the given source pixel
        dfs(image, sr, sc, image[sr][sc], color);

        return image; // Return the modified image
    }
};




/************************************************************
*  Problem: 733. Flood Fill
*  Link   : https://leetcode.com/problems/flood-fill/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-04
*  ----------------------------------------------
*  Problem Description:
*  Given a 2D grid (image) where each cell has an integer value
*  representing a color, you need to perform a "flood fill."
*  Starting from a given pixel (sr, sc), change all connected
*  pixels of the same color to a new color.

*  Approach:
*  - Use Breadth-First Search (BFS) to traverse all connected
*    pixels starting from the source pixel.
*  - Use a queue to process pixels iteratively.
*  - Avoid a separate visited array by directly checking the color.

*  Time Complexity : O(N * M) - Each pixel is visited once.
*  Space Complexity: O(N * M) - For the queue in the worst case.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to perform the flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();          // Number of rows
        int m = image[0].size();       // Number of columns

        int sourceColor = image[sr][sc]; // Color of the starting pixel
        if (sourceColor == color) return image; // If the new color is the same, no changes needed

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Queue for BFS, storing the current cell coordinates
        queue<pair<int, int>> q;
        q.push({sr, sc}); // Start from the given source pixel

        // Change the starting pixel's color
        image[sr][sc] = color;

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front(); // Get the front of the queue
            q.pop();

            // Process all four neighbors
            for (auto [dx, dy] : directions) {
                int nx = x + dx; // New row
                int ny = y + dy; // New column

                // Check if the neighbor is valid and matches the source color
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == sourceColor) {
                    // Change its color
                    image[nx][ny] = color;
                    // Add it to the queue for further processing
                    q.push({nx, ny});
                }
            }
        }

        return image; // Return the modified image
    }
};
