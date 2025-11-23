#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#include <cmath>


class Solution {
public:
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = 0;
        for(const auto& edge : edges) {
            n = max({n, edge[0] + 1, edge[1] + 1});
        }
        if (n == 0 && !edges.empty()) {
             n = edges.size() + 1;
        } else if (n == 0 && edges.empty()) {
            n = 1;
        }


        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            if (edge[0] < n && edge[1] < n) {
                children[edge[0]].push_back(edge[1]);
                children[edge[1]].push_back(edge[0]);
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n1 = 0;
        for(const auto& edge : edges1) {
            n1 = max({n1, edge[0] + 1, edge[1] + 1});
        }
        if (n1 == 0 && !edges1.empty()) n1 = edges1.size() + 1;
        else if (n1 == 0 && edges1.empty()) n1 = 1;

        int n2 = 0;
        for(const auto& edge : edges2) {
            n2 = max({n2, edge[0] + 1, edge[1] + 1});
        }
        if (n2 == 0 && !edges2.empty()) n2 = edges2.size() + 1;
        else if (n2 == 0 && edges2.empty()) n2 = 1;


        vector<int> count1 = build(edges1, k);
        
        vector<int> count2 = build(edges2, k - 1);
        
        int maxCount2 = 0;
        if (!count2.empty()) {
            maxCount2 = *max_element(count2.begin(), count2.end());
        }
        
        vector<int> res(n1);
        for (int i = 0; i < n1; i++) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }
};