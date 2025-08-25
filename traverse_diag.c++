#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res(n * m);
        int k = 0;
        vector<int> buf;
        for (int d = 0; d < n + m - 1; ++d) {
            buf.clear();
            int r = d < m ? 0 : d - m + 1;
            int c = d < m ? d : m - 1;
            while (r < n && c >= 0) {
                buf.push_back(matrix[r][c]);
                ++r; --c;
            }
            if (d % 2 == 0) reverse(buf.begin(), buf.end());
            for (int x : buf) res[k++] = x;
        }
        return res;
    }
};
