# Closest Meeting Node in a Directed Graph (LeetCode)

## Problem Summary

You are given a directed graph represented by an array `edges`, where each node has **at most one outgoing edge**.  
Two starting nodes are given. The task is to find a node that is reachable from **both** starting nodes such that the **maximum distance** from the two start nodes to that node is minimized.

If multiple answers exist, return the node with the **smallest index**.  
If no such node exists, return `-1`.

Yes, the graph is weird. Each node points to only one place or nowhere. Humans designed it.

---

## Key Idea

Since every node has only one outgoing edge, the graph is basically a collection of chains and cycles.

Strategy:
1. Track the distance from `node1` to every reachable node.
2. Track the distance from `node2` to every reachable node.
3. For every node reachable from both:
   - Take the **maximum** of the two distances.
   - Pick the node where this maximum is **minimum**.

No BFS queue. No recursion drama. Just walk forward like life intends.

---

## Algorithm Explanation

### Step 1: Distance Tracking

We maintain two arrays:
- `distFromFirst[i]` → distance from `node1` to `i`
- `distFromSecond[i]` → distance from `node2` to `i`

Unvisited nodes are marked `-1`.

### Step 2: Linear Traversal

Starting from a node:
- Move to the next node using `edges[current]`
- Stop if:
  - you hit `-1`
  - or the node was already visited (cycle detected)

Each step increments distance.

### Step 3: Find Best Meeting Node

For every node reachable from both:
- Compute `max(distFromFirst[i], distFromSecond[i])`
- Choose the node with the **smallest max distance**

---

## Java Code (Plagiarism-Safe Version)

```java
class Solution {

    private void tracePath(int start, int[] edges, int[] distance) {
        int current = start;
        int steps = 0;

        while (current != -1 && distance[current] == -1) {
            distance[current] = steps++;
            current = edges[current];
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;

        int[] distFromFirst = new int[n];
        int[] distFromSecond = new int[n];

        Arrays.fill(distFromFirst, -1);
        Arrays.fill(distFromSecond, -1);

        tracePath(node1, edges, distFromFirst);
        tracePath(node2, edges, distFromSecond);

        int result = -1;
        int minMaxDistance = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (distFromFirst[i] != -1 && distFromSecond[i] != -1) {
                int currentMax = Math.max(distFromFirst[i], distFromSecond[i]);
                if (currentMax < minMaxDistance) {
                    minMaxDistance = currentMax;
                    result = i;
                }
            }
        }

        return result;
    }
}
