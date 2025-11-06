//problem link-> https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06
import java.util.*;

class Solution {
    // Disjoint Set Union (Union-Find) with path compression + union by size
    static final class DSU {
        int[] parent, size;
        DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) { int t = a; a = b; b = t; }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    public int[] processQueries(int n, int[][] connections, int[][] queries) {
        // Keep index 0 aligned with the original behavior that used n++.
        n++; // nodes are effectively [0..n-1]

        // 1) Build components with DSU
        DSU dsu = new DSU(n);
        for (int[] e : connections) {
            // e[0] -- e[1]
            dsu.unite(e[0], e[1]);
        }

        // 2) Count nodes per component root
        int[] compCount = new int[n];
        for (int i = 0; i < n; i++) {
            compCount[ dsu.find(i) ]++;
        }

        // 3) Exclusive prefix to compute start offsets for each component bucket
        int[] start = new int[n];
        {
            int running = 0;
            for (int i = 0; i < n; i++) {
                int c = compCount[i];
                start[i] = running;
                running += c;
            }
        }

        // 4) Scatter nodes into a single compact bucket array grouped by component
        int[] write = Arrays.copyOf(start, n);  // moving insert pointer per component
        int[] bucket = new int[n];              // holds all nodes, grouped by comp
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            bucket[ write[root]++ ] = i;
        }

        // For each component, we know its range [start[root], end[root])
        int[] end = Arrays.copyOf(write, n);

        // 5) Pointer per component to the "first not-offline" candidate (advances lazily)
        int[] head = Arrays.copyOf(start, n);

        // 6) Process queries
        boolean[] offline = new boolean[n];
        int[] out = new int[queries.length];
        int m = 0;

        for (int[] q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 1) {
                // Query: return x if online; otherwise, first online node in x's component or -1
                if (!offline[x]) {
                    out[m++] = x;
                } else {
                    int root = dsu.find(x);
                    int i = head[root];
                    int hi = end[root];

                    while (i < hi && offline[bucket[i]]) i++;
                    head[root] = i;

                    out[m++] = (i == hi ? -1 : bucket[i]);
                }
            } else {
                // type == 2: mark x offline
                offline[x] = true;
            }
        }

        return Arrays.copyOf(out, m);
    }
}
