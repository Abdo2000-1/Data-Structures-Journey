# Binary Min-Heap - Complexity Analysis

A clear and concise summary of the Time and Space Complexity for the dynamic array-based Binary Min-Heap implementation.

---

## 1. Time Complexity

Since a Binary Heap is always maintained as a Complete Binary Tree, its height is strictly guaranteed to be bounded by $O(\log n)$. This structural property ensures highly efficient structural modifications.

| Operation / Method | Time Complexity | Reason / Description |
| :--- | :---: | :--- |
| **`isEmpty()`** | $O(1)$ | Direct condition check on the `size` variable (`size == 0`). |
| **`left()` / `right()` / `parent()`** | $O(1)$ | Basic arithmetic formulas to compute the index in a single step. |
| **`top()`** | $O(1)$ | The minimum value is always stable at the root (`array[0]`). |
| **`Heapify_up()`** | $O(\log n)$ | Worst case: travels from the bottom (leaf) to the top (root) along the tree height. |
| **`Heapify_down()`** | $O(\log n)$ | Worst case: travels from the top (root) down to the bottom (leaf) along the tree height. |
| **`push()`** | $O(\log n)$ | Dominated by the execution of the `Heapify_up()` function. |
| **`pop()`** | $O(\log n)$ | Dominated by the execution of the `Heapify_down()` function. |

---

## 2. Space Complexity

Analysis of memory consumption within the Heap:

### Total Space Complexity: $O(n)$
* Where $n$ is the allocated array `capacity`. Elements are stored sequentially in a contiguous memory block without the overhead of extra pointers (`Node* left, right`), making it extremely memory-efficient compared to BST or AVL trees.

### Auxiliary Space Complexity: $O(\log n)$
* Recursive methods (`Heapify_up` and `Heapify_down`) utilize memory frames on the **Call Stack**.
* The maximum depth of the call stack is directly proportional to the height of the tree, which is always bounded by $O(\log n)$.

---

## Conclusion
The **Min-Heap** provides an optimal trade-off by guaranteeing instantaneous $O(1)$ time access to the minimum element, and strict $O(\log n)$ time for insertions and deletions, combined with a highly compact $O(n)$ array storage footprint.