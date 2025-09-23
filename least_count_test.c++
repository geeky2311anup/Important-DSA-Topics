#include <bits/stdc++.h>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> parent, rank, componentCost;

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        parent.resize(n, -1);
        rank.resize(n, 0);
        componentCost.assign(n, ~0); // Initialize with all 1s in binary (~0)

        // Step 1: Construct the connected components using DSU (Union-Find)
        for (const auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        // Step 2: Compute the minimum AND cost for each component
        for (const auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        // Step 3: Process queries
        vector<int> result;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];

            if (find(u) != find(v)) {
                result.push_back(-1); // Nodes are in different components
            } else {
                result.push_back(componentCost[find(u)]);
            }
        }
        return result;
    }

private:
    // Find function with path compression
    int find(int node) {
        if (parent[node] == -1) return node; 
        return parent[node] = find(parent[node]);
    }

    // Union function with union by rank
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return; // Already in the same component

        if (rank[rootU] < rank[rootV]) swap(rootU, rootV);

        parent[rootV] = rootU;
        if (rank[rootU] == rank[rootV]) rank[rootU]++;
    }
};
