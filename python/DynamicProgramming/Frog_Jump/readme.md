## 🐸 Frog Jump – Recursive Solution

This folder contains the first solution to the **Frog Jump** problem using a naive recursive approach.

---

### 📘 Problem Statement

A frog is at the first stone of a river represented by an array `heights[]`. It wants to reach the last stone. The frog can jump either **1 or 2 steps forward**. The cost of a jump is the **absolute difference** in height between the current stone and the destination stone.

**Goal:** Minimize the total cost to reach the last stone.

---

### 🧠 Approach: Simple Recursion

We use a recursive function to explore all possible paths to the last stone. At each step, the frog can jump:
- From `i-1` → cost = `abs(heights[i] - heights[i-1])`
- From `i-2` → cost = `abs(heights[i] - heights[i-2])` (if `i > 1`)

The base case is:
- `cost(0) = 0` → Starting point, no cost.

---

### 📄 Code: `1_recursion.py`

```python
def frog_jump(index, heights):
    if index == 0:
        return 0

    one = frog_jump(index - 1, heights) + abs(heights[index] - heights[index - 1])
    two = float('inf')
    if index > 1:
        two = frog_jump(index - 2, heights) + abs(heights[index] - heights[index - 2])

    return min(one, two)

if __name__ == "__main__":
    heights = [10, 30, 40, 20]
    print(frog_jump(len(heights) - 1, heights))  # Output: 30
```

---

### 📈 Time Complexity
- **O(2ⁿ)** — exponential due to overlapping subproblems.

### 📉 Space Complexity
- **O(n)** — recursion stack depth.