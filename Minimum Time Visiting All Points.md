# 🚶‍♂️ Walking, Diagonal Moonwalking, and Why Math Saves Time  
## LeetCode 1266 – Minimum Time Visiting All Points

Because apparently walking in straight lines wasn’t enough.

---

## 🧠 Problem Summary

You are given a list of 2D points.  
You start at the first point and must visit every point **in order**.

### Allowed moves (each takes 1 second):
- Up, Down, Left, Right  
- Diagonal (change both x and y by 1)

Your job: **calculate the minimum time** to visit all points.

---

## 💡 Core Insight (The Only Thing That Matters)

To move from point `A(x1, y1)` to point `B(x2, y2)`:

- You can move diagonally to reduce **both x and y**
- Once one coordinate is aligned, you move straight for the rest

### Result:
The minimum time needed is:

max(|x1 - x2|, |y1 - y2|)


Because diagonal moves cover the smaller distance,  
and straight moves finish what’s left.

---

## 🧮 How the Algorithm Works

For each consecutive pair of points:
1. Compute absolute difference in x
2. Compute absolute difference in y
3. Add the larger of the two to the answer

Repeat until all points are visited.

---

## 🧑‍💻 Java Implementation

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length;
        int totalTime = 0;

        for (int i = 0; i < n - 1; i++) {
            int dx = Math.abs(points[i][0] - points[i + 1][0]);
            int dy = Math.abs(points[i][1] - points[i + 1][1]);
            totalTime += Math.max(dx, dy);
        }

        return totalTime;
    }
}
