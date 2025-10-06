#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        pq.push({grid[0][0], {0, 0}});
        minTime[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [currTime, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            if (visited[r][c]) continue;
            visited[r][c] = 1;
            if (r == n - 1 && c == n - 1) return currTime;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int nextTime = max(currTime, grid[nr][nc]);
                    if (nextTime < minTime[nr][nc]) {
                        minTime[nr][nc] = nextTime;
                        pq.push({nextTime, {nr, nc}});
                    }
                }
            }
        }
        return minTime[n - 1][n - 1];
    }
};
