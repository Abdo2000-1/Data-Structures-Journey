# BST Complexity Analysis

## Time Complexity

| Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- |
| **Insert** | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| **Search** | $O(1)$ | $O(\log n)$ | $O(n)$ |
| **Delete** | $O(1)$ | $O(\log n)$ | $O(n)$ |
| **DFS Traversals** (Pre/In/Post-Order) | $O(n)$ | $O(n)$ | $O(n)$ |
| **BFS Traversal** (Level-Order) | $O(n)$ | $O(n)$ | $O(n)$ |

---

## Space Complexity

| Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- |
| **Tree Storage** | $O(n)$ | $O(n)$ | $O(n)$ |
| **Insert / Search / Delete** (Recursive Stack) | $O(1)$ | $O(\log n)$ | $O(n)$ |
| **DFS Traversals** (Recursive Stack) | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| **BFS Traversal** (Queue Size) | $O(n)$ | $O(n)$ | $O(n)$ |

---

## Key Notes

* **Best Case Details:** * For **Search** and **Delete**, the best case is $O(1)$ if the target node is the root of the tree.
  * For **Insert** (and recursive memory stack), the best case is $O(1)$ if the tree is completely empty. If the tree is perfectly balanced, inserting a leaf node takes $O(\log n)$ time and uses $O(\log n)$ recursive stack space.
* **Average Case:** Occurs when the tree is reasonably balanced. The height of the tree is $h = \log n$.
* **Worst Case:** Occurs when elements are inserted in sorted (ascending or descending) order. The tree becomes a skewed tree (essentially a linked list), where the height becomes $h = n$.