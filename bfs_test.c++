#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;

        // DFS function to explore each connected component
        function<pair<int, int>(int)> dfs = [&](int node) {
            stack<int> stk;
            stk.push(node);
            visited[node] = true;

            int nodes = 0, edgeCount = 0;

            while (!stk.empty()) {
                int u = stk.top();
                stk.pop();
                nodes++;

                for (int v : graph[u]) {
                    edgeCount++;
                    if (!visited[v]) {
                        visited[v] = true;
                        stk.push(v);
                    }
                }
            }

            edgeCount /= 2;  // Each edge is counted twice

            return make_pair(nodes, edgeCount);
        };

        // Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                auto [nodes, edgeCount] = dfs(i);

                // A complete graph has nodes * (nodes - 1) / 2 edges
                if (edgeCount == (nodes * (nodes - 1)) / 2) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};
