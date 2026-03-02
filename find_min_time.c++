#include <vector>
#include <queue>
using namespace std;

// Structure to represent a cell state in the priority queue
class State {
public:
    int x;    // row index
    int y;    // column index
    int dis;  // current shortest distance (time)

    // Constructor
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
    const int inf = 0x3f3f3f3f;  // A large value representing infinity

    int minTimeToReach(vector<vector<int>> &moveTime) {
        int n = moveTime.size();        // number of rows
        int m = moveTime[0].size();     // number of columns

        // Distance matrix to store minimum time to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, inf));

        // Visited matrix to avoid reprocessing nodes
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Directions for moving: down, up, right, left
        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Starting point initialization
        dist[0][0] = 0;

        // Min-heap (priority queue) based on shortest distance
        auto comparator = [](const State &a, const State &b) {
            return a.dis > b.dis;  // smallest distance has highest priority
        };

        priority_queue<State, vector<State>, decltype(comparator)> pq(comparator);
        pq.push(State(0, 0, 0));  // push starting cell

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            // Skip if already processed
            if (visited[current.x][current.y]) {
                continue;
            }

            // If destination reached, stop early
            if (current.x == n - 1 && current.y == m - 1) {
                break;
            }

            visited[current.x][current.y] = 1;

            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nx = current.x + directions[i][0];
                int ny = current.y + directions[i][1];

                // Check boundary conditions
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                // Calculate the earliest possible arrival time:
                // - Wait until moveTime[nx][ny] if needed
                // - Add movement cost (depends on parity of current position)
                int newDist = max(dist[current.x][current.y], moveTime[nx][ny])
                              + (current.x + current.y) % 2 + 1;

                // Relaxation step
                if (dist[nx][ny] > newDist) {
                    dist[nx][ny] = newDist;
                    pq.push(State(nx, ny, newDist));
                }
            }
        }

        // Return minimum time to reach bottom-right corner
        return dist[n - 1][m - 1];
    }
};
