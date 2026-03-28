#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // DFS to color the tree in bipartite manner (0/1)
    // Also counts nodes belonging to a specific parity group
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        
        // Assign color based on depth (even → 0, odd → 1)
        color[node] = depth % 2;

        // Count nodes of opposite parity group
        // (1 - depth % 2 ensures alternating count)
        int res = 1 - (depth % 2);

        // Traverse all adjacent nodes (children)
        for (int child : children[node]) {
            if (child == parent) {
                continue; // avoid going back to parent
            }
            res += dfs(child, node, depth + 1, children, color);
        }

        return res;
    }

    // Build adjacency list and compute counts of two partitions
    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;

        // Adjacency list representation of tree
        vector<vector<int>> children(n);
        
        for (const auto& edge : edges) {
            // Add undirected edge
            if (edge[0] < n && edge[1] < n) {
                children[edge[0]].push_back(edge[1]);
                children[edge[1]].push_back(edge[0]);
            }
        }
        
        // Run DFS from node 0 to color and count
        int countOpposite = dfs(0, -1, 0, children, color);
        
        // Return counts of both partitions:
        // {nodes with color 1, nodes with color 0}
        return {countOpposite, n - countOpposite};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        // Store bipartite coloring for both trees
        vector<int> color1(n);
        vector<int> color2(m);
        
        // Get counts of partitions for both trees
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        
        // Choose maximum possible nodes from second tree
        int maxCount2 = max(count2[0], count2[1]);
        
        vector<int> res(n);
        
        // For each node in first tree:
        // Add its partition size + best partition from second tree
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + maxCount2;
        }

        return res;
    }
};
