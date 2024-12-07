/************************************************************
*  Problem: Bellman Ford
*  Link   : https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTabValue=SUBMISSION
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-07
*  ----------------------------------------------

*  Problem Description:
*  Given a directed, weighted graph with N vertices and M edges,
*  calculate the shortest distance from the source vertex (src)
*  to all other vertices. If a vertex is unreachable, it should
*  remain assigned a large value (infinity).

*  Approach:
*  - Initialize all distances to infinity, except for the source
*    vertex, which is set to 0.
*  - For (N-1) iterations, iterate over all edges and relax them
*    to update the shortest path to each vertex.
*  - Return the distance array containing the shortest distances.

*  Time Complexity : O(N * M) 
*      N: Number of vertices
*      M: Number of edges
*  Space Complexity: O(N)
*      For storing distances.

*  Platform: Naukri Code360
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate shortest distances using Bellman-Ford algorithm
vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Initialize distance array with a large value (infinity)
    vector<int> distance(n + 1, 100000000);

    // Distance to the source vertex is 0
    distance[src] = 0;

    // Relax all edges (N-1) times to find the shortest paths
    for (int i = 1; i <= n - 1; i++) {
        // Iterate through all edges
        for (vector<int> edge : edges) {
            int u = edge[0]; // Source vertex of the edge
            int v = edge[1]; // Destination vertex of the edge
            int w = edge[2]; // Weight of the edge
            
            // Relax the edge if a shorter path is found
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Return the distance array
    return distance;
}
