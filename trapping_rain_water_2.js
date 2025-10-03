/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    if (!heightMap || heightMap.length === 0) return 0;
    const m = heightMap.length, n = heightMap[0].length;
    if (m <= 2 || n <= 2) return 0;

    class MinHeap {
        constructor(){ this.a = []; }
        size(){ return this.a.length; }
        push(x){
            this.a.push(x);
            let i = this.a.length - 1;
            while (i > 0){
                let p = (i - 1) >> 1;
                if (this.a[p].h <= this.a[i].h) break;
                [this.a[p], this.a[i]] = [this.a[i], this.a[p]];
                i = p;
            }
        }
        pop(){
            if (this.a.length === 0) return null;
            const res = this.a[0];
            const last = this.a.pop();
            if (this.a.length > 0){
                this.a[0] = last;
                let i = 0;
                while (true){
                    let l = i * 2 + 1, r = i * 2 + 2, smallest = i;
                    if (l < this.a.length && this.a[l].h < this.a[smallest].h) smallest = l;
                    if (r < this.a.length && this.a[r].h < this.a[smallest].h) smallest = r;
                    if (smallest === i) break;
                    [this.a[i], this.a[smallest]] = [this.a[smallest], this.a[i]];
                    i = smallest;
                }
            }
            return res;
        }
    }

    const visited = Array.from({length: m}, () => Array(n).fill(false));
    const heap = new MinHeap();

    for (let i = 0; i < m; i++){
        if (!visited[i][0]) { heap.push({r:i,c:0,h:heightMap[i][0]}); visited[i][0] = true; }
        if (!visited[i][n-1]) { heap.push({r:i,c:n-1,h:heightMap[i][n-1]}); visited[i][n-1] = true; }
    }
    for (let j = 1; j < n-1; j++){
        if (!visited[0][j]) { heap.push({r:0,c:j,h:heightMap[0][j]}); visited[0][j] = true; }
        if (!visited[m-1][j]) { heap.push({r:m-1,c:j,h:heightMap[m-1][j]}); visited[m-1][j] = true; }
    }

    let total = 0;
    const dr = [1,-1,0,0], dc = [0,0,1,-1];

    while (heap.size() > 0){
        const cur = heap.pop();
        for (let k = 0; k < 4; k++){
            const nr = cur.r + dr[k], nc = cur.c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (visited[nr][nc]) continue;
            visited[nr][nc] = true;
            const nh = heightMap[nr][nc];
            if (nh < cur.h){
                total += (cur.h - nh);
                heap.push({r:nr,c:nc,h:cur.h});
            } else {
                heap.push({r:nr,c:nc,h:nh});
            }
        }
    }

    return total;
};
