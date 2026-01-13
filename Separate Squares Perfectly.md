# Binary Search + Geometry
## Separate Squares Perfectly: Because Half the Area Deserves Respect

Given a set of squares on a 2D plane, we want to find a horizontal line that splits the total area into two equal halves.  
Squares can be partially above and partially below the line. The task is to return the `y` coordinate of that line.

Example:

Squares: [x, y, size]  
[0, 0, 2]   [0, 2, 2]   [2, 0, 2]

We want a horizontal line `lineY` such that:

Area above lineY == Area below lineY

------------------------------------------------------------

🖼️ Visualization of Squares and Line

Suppose our squares are positioned as above:

        y=4 ───────────────
                    □       <- Square at (0,2) size=2
                    □       
        y=2 ───────────────
        □       □           <- Squares at (0,0) and (2,0) size=2
        □       □
        y=0 ───────────────
        
We need a line `lineY` such that the total area above equals total area below.  
Notice how the line may intersect squares partially:

- Full squares above the line contribute their full area above
- Full squares below the line contribute their full area below
- Intersected squares are split proportionally

------------------------------------------------------------

❌ Why Random Guessing Fails

A naive approach might suggest: “Just take the middle of the minY and maxY.”  

Wrong. Squares differ in size and position. Some squares may intersect the line, meaning only part of their area contributes to above or below.  
Random guessing will almost certainly fail.

------------------------------------------------------------

✅ Solution: Binary Search on `y` Using Area Difference

Define a helper function:

areaDiff(lineY) = areaAbove(lineY) - areaBelow(lineY)

- If areaDiff > 0, the line is too low → more area is above  
- If areaDiff < 0, the line is too high → more area is below  

We use binary search to find the lineY where areaDiff ≈ 0.  
Repeating ~60 iterations ensures high precision.

------------------------------------------------------------

🎁 Bonus Gift: Why This Idea Works

At each step, we calculate the exact **contribution of each square** above and below the line.  
By using binary search, we systematically narrow the region until the difference converges to zero.  
This works because areaDiff is a **monotonic function** of the line’s y-coordinate: moving the line up decreases area above and increases area below, guaranteeing convergence.  

We do exactly what’s necessary—no guessing, no wasted computation, just reliable precision.

------------------------------------------------------------

🛠️ Algorithm Explanation

1. Define areaDiff(lineY):
   - Loop through all squares
   - Compute full or partial area above and below the line
   - Return areaAbove - areaBelow
2. Initialize low = 0, high = 2e9
3. Repeat 60 times:
   - mid = (low + high)/2
   - diff = areaDiff(mid)
   - If diff > 0 → low = mid
   - Else → high = mid
4. Return high (or low; they converge)

------------------------------------------------------------

Java Code:

    class Solution {
        private double areaDiff(double lineY, int[][] squares) {
            double areaAbove = 0, areaBelow = 0;

            for (int[] sq : squares) {
                int x = sq[0], y = sq[1], size = sq[2];
                double squareArea = (double) size * size;

                if (lineY <= y) {
                    areaAbove += squareArea;
                } else if (lineY >= y + size) {
                    areaBelow += squareArea;
                } else {
                    double aboveHeight = y + size - lineY;
                    double belowHeight = lineY - y;
                    areaAbove += size * aboveHeight;
                    areaBelow += size * belowHeight;
                }
            }
            return areaAbove - areaBelow;
        }

        public double separateSquares(int[][] squares) {
            double low = 0, high = 2e9;

            for (int i = 0; i < 60; i++) {
                double mid = (low + high) / 2.0;
                double diff = areaDiff(mid, squares);

                if (diff > 0) {
                    low = mid;
                } else {
                    high = mid;
                }
            }

            return high;
        }
    }

------------------------------------------------------------

💻 C++ Solution

    class Solution {
    public:
        double areaDiff(double lineY, vector<vector<int>>& squares) {
            double areaAbove = 0, areaBelow = 0;
            for (auto &sq : squares) {
                int x = sq[0], y = sq[1], size = sq[2];
                double squareArea = (double) size * size;

                if (lineY <= y) areaAbove += squareArea;
                else if (lineY >= y + size) areaBelow += squareArea;
                else {
                    double aboveHeight = y + size - lineY;
                    double belowHeight = lineY - y;
                    areaAbove += size * aboveHeight;
                    areaBelow += size * belowHeight;
                }
            }
            return areaAbove - areaBelow;
        }

        double separateSquares(vector<vector<int>>& squares) {
            double low = 0, high = 2e9;
            for (int i = 0; i < 60; i++) {
                double mid = (low + high) / 2.0;
                double diff = areaDiff(mid, squares);
                if (diff > 0) low = mid;
                else high = mid;
            }
            return high;
        }
    };

------------------------------------------------------------

💻 Python Solution

    class Solution:
        def areaDiff(self, lineY, squares):
            areaAbove = 0
            areaBelow = 0
            for x, y, size in squares:
                squareArea = size * size
                if lineY <= y:
                    areaAbove += squareArea
                elif lineY >= y + size:
                    areaBelow += squareArea
                else:
                    aboveHeight = y + size - lineY
                    belowHeight = lineY - y
                    areaAbove += size * aboveHeight
                    areaBelow += size * belowHeight
            return areaAbove - areaBelow

        def separateSquares(self, squares):
            low, high = 0, 2e9
            for _ in range(60):
                mid = (low + high) / 2.0
                diff = self.areaDiff(mid, squares)
                if diff > 0:
                    low = mid
                else:
                    high = mid
            return high

------------------------------------------------------------

💻 JavaScript Solution

    var areaDiff = function(lineY, squares) {
        let areaAbove = 0, areaBelow = 0;
        for (let sq of squares) {
            let [x, y, size] = sq;
            let squareArea = size * size;
            if (lineY <= y) areaAbove += squareArea;
            else if (lineY >= y + size) areaBelow += squareArea;
            else {
                let aboveHeight = y + size - lineY;
                let belowHeight = lineY - y;
                areaAbove += size * aboveHeight;
                areaBelow += size * belowHeight;
            }
        }
        return areaAbove - areaBelow;
    };

    var separateSquares = function(squares) {
        let low = 0, high = 2e9;
        for (let i = 0; i < 60; i++) {
            let mid = (low + high) / 2;
            let diff = areaDiff(mid, squares);
            if (diff > 0) low = mid;
            else high = mid;
        }
        return high;
    };

------------------------------------------------------------

⏱️ Complexity Analysis

Time Complexity: O(n * log(maxY))  
Space Complexity: O(1)

------------------------------------------------------------

📌 Final Thoughts

- Naive guessing fails because partial areas exist  
- Binary search guarantees convergence due to monotonic areaDiff  
- Geometry + algorithm = precise, reliable, elegant  
- Squares are split perfectly, and we don’t lose sleep over it

Upvote if your line split like a pro 🔼  
Comment if you still trust your gut instinct 👇
