# Complexity Analysis: Singly Linked List (Without Tail & Length)

This document provides a comprehensive theoretical and practical complexity analysis for the customized `LinkedList` implementation. This version of the linked list operates **without** maintaining a `tail` pointer or a `length` variable, relying solely on the `head` pointer.

---

## 1. Executive Summary Table

| Method / Operation | Time Complexity (Worst Case) | Time Complexity (Best Case) | Space Complexity (Auxiliary) | Main Driving Factor |
| :--- | :---: | :---: | :---: | :--- |
| **`add_element(int value)`** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Immediate insertion at the front (`head`). |
| **`get_tail()`** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Linear scan required from `head` to find the last node. |
| **`print()`** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | Sequential traversal of all $N$ nodes to print data. |


