#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        
        for (const auto& edge : edges) {
            if (edge[0] < n && edge[1] < n) {
                children[edge[0]].push_back(edge[1]);
                children[edge[1]].push_back(edge[0]);
            }
        }
        
        int res_dfs = dfs(0, -1, 0, children, color);
        
        return {res_dfs, n - res_dfs};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<int> color1(n);
        vector<int> color2(m);
        
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        
        int maxCount2 = max(count2[0], count2[1]);
        
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + maxCount2;
        }
        return res;
    }
};