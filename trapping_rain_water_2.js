/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {

    // Edge case: empty grid
    if (!heightMap || heightMap.length === 0) return 0;

    const m = heightMap.length, n = heightMap[0].length;

    // If grid is too small, water cannot be trapped
    if (m <= 2 || n <= 2) return 0;

    // ---------------- MIN HEAP IMPLEMENTATION ----------------
    // We use a min-heap to always process the lowest boundary first
    class MinHeap {
        constructor(){ this.a = []; }

        size(){ return this.a.length; }

        // Insert element into heap and maintain heap property
        push(x){
            this.a.push(x);
            let i = this.a.length - 1;

            // Bubble up
            while (i > 0){
                let parent = (i - 1) >> 1;
                if (this.a[parent].h <= this.a[i].h) break;

                [this.a[parent], this.a[i]] = [this.a[i], this.a[parent]];
                i = parent;
            }
        }

        // Remove and return smallest element (root)
        pop(){
            if (this.a.length === 0) return null;

            const top = this.a[0];
            const last = this.a.pop();

            if (this.a.length > 0){
                this.a[0] = last;
                let i = 0;

                // Bubble down
                while (true){
                    let left = 2 * i + 1;
                    let right = 2 * i + 2;
                    let smallest = i;

                    if (left < this.a.length && this.a[left].h < this.a[smallest].h)
                        smallest = left;

                    if (right < this.a.length && this.a[right].h < this.a[smallest].h)
                        smallest = right;

                    if (smallest === i) break;

                    [this.a[i], this.a[smallest]] = [this.a[smallest], this.a[i]];
                    i = smallest;
                }
            }

            return top;
        }
    }

    // ---------------- INITIALIZATION ----------------

    // Track visited cells so we don't process them again
    const visited = Array.from({length: m}, () => Array(n).fill(false));

    const heap = new MinHeap();

    // Step 1: Push all boundary cells into heap
    // These act as initial "walls"
    for (let i = 0; i < m; i++){
        heap.push({r: i, c: 0, h: heightMap[i][0]});
        heap.push({r: i, c: n - 1, h: heightMap[i][n - 1]});
        visited[i][0] = true;
        visited[i][n - 1] = true;
    }

    for (let j = 1; j < n - 1; j++){
        heap.push({r: 0, c: j, h: heightMap[0][j]});
        heap.push({r: m - 1, c: j, h: heightMap[m - 1][j]});
        visited[0][j] = true;
        visited[m - 1][j] = true;
    }

    // Directions for exploring neighbors (down, up, right, left)
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];

    let water = 0; // total trapped water

    // ---------------- MAIN LOGIC ----------------
    // Similar to Dijkstra / BFS from boundary inward
    while (heap.size() > 0){
        const curr = heap.pop();

        // Explore all 4 neighbors
        for (let k = 0; k < 4; k++){
            const nr = curr.r + dr[k];
            const nc = curr.c + dc[k];

            // Skip invalid or already visited cells
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;

            const neighborHeight = heightMap[nr][nc];

            // If neighbor is lower, water can be trapped
            if (neighborHeight < curr.h){
                water += (curr.h - neighborHeight);

                // Push with updated height (water level becomes boundary)
                heap.push({r: nr, c: nc, h: curr.h});
            } else {
                // No water trapped, push actual height
                heap.push({r: nr, c: nc, h: neighborHeight});
            }
        }
    }

    // Return total trapped water
    return water;
};
