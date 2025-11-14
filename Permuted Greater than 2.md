# 📘 Solution Explanation + Java Code

## 💡 Problem Understanding

You are given three integers per test case:

- **x**
- **y**
- **z**

The goal is to determine whether the conditions allow us to print **"Yes"** or **"No"**.

The logic is based on two main checks:

---

## ✅ 1. Special Case Check
If `y == 0` **and**  
`x - z <= 1`  
then the answer is always **"Yes"`**.

This means when `y` is zero, the only thing that matters is whether the gap between `x` and `z` is at most 1.

---

## ✅ 2. General Case Check
If `x <= z`,  
then also print **"Yes"`**.

Meaning: if `x` is already within or below the allowed limit, it's automatically valid.

---

## ❌ Otherwise
If neither of the above conditions are satisfied, the result is **"No"`**.

---

# 🧠 Intuition

The problem essentially checks if:  
- A special relaxation rule (`y == 0`) applies *and* the gap is small, OR  
- `x` already satisfies the general requirement (`x <= z`)

If both fail → not possible.

---

# 🛠️ Final Java Code (Single `.java` File)

```java
import java.util.*;

public class Main {

    // Function that checks if the conditions are satisfied
    private static boolean isPossible(int x, int y, int z) {

        // Special rule when y == 0
        if (y == 0 && (x - z) <= 1) {
            return true;
        }

        // General rule
        if (x <= z) {
            return true;
        }

        // Otherwise not possible
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();  // number of test cases
        while (t-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();

            boolean result = isPossible(x, y, z);
            System.out.println(result ? "Yes" : "No");
        }

        sc.close();
    }
}
