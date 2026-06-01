#include <iostream>
#include <vector>
#include <cassert> 
#include <queue> 
#include <string>
#include <algorithm>

using namespace std;

/**
* @brief Struct representing a binary tree node (currently unused in array-based heap).
*/
struct Node {
    int data{};
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MinHeap {
private:
    int* array{}; ///< Dynamic array to store heap elements
    int size{}; ///< Current number of elements in the heap
    int capacity{ 1000 }; ///< Maximum capacity of the heap array

public:

    /**
     * @brief Constructor to initialize the heap with a default capacity.
     */
    MinHeap() {
        array = new int [capacity] {};
        size = 0;
    }

    /**
     * @brief Checks if the heap is empty.
     * @return true if empty, false otherwise.
     */
    bool isEmpty() {
        return size == 0;
    }

    /**
     * @brief Calculates the index of the left child.
     * @param node Index of the current node.
     * @return Index of the left child, or -1 if out of bounds.
     */
    int left(int node) {
        int p = 2 * node + 1;
        if (p >= size)
            return -1;
        return p;
    }

    /**
     * @brief Calculates the index of the right child.
     * @param node Index of the current node.
     * @return Index of the right child, or -1 if out of bounds.
     */
    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    /**
     * @brief Calculates the index of the parent node.
     * @param node Index of the current node.
     * @return Index of the parent node, or -1 if the node is root.
     */
    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    /**
     * @brief Restores the min-heap property by moving a node up.
     * @param idx Index of the node to heapify up.
     */
    void Heapify_up(int idx)
    {
        int Parent = parent(idx);


        if (idx == 0 || array[Parent] < array[idx]) return;


        if (array[Parent] > array[idx]) {
            swap(array[idx], array[Parent]);
            // Fixed logic: Passed Parent directly to avoid infinite recursion/bugs
            Heapify_up(Parent);
        }
    }

    /**
     * @brief Inserts a new value into the min-heap.
     * @note Time Complexity: O(Log n)
     * @param val The value to be inserted.
     */
    void push(int val) { // O(Log n)
        assert(size + 1 <= capacity);
        array[size++] = val;
        Heapify_up(size - 1);
    }

    /**
     * @brief Returns the minimum element (root) of the heap.
     * @return The minimum value.
     */
    int top() {
        assert(!isEmpty());
        return array[0]; // Minimum
    }

    /**
     * @brief Restores the min-heap property by moving a node down.
     * @param Parent Index of the node to heapify down.
     */
    void Heapify_down(int Parent) { // O(Log n)
        int child = left(Parent);
        int right_child = right(Parent);

        if (child == -1) return; // No Children

        // is Right Smaller Than Left  ?
        if (right_child != -1 && array[right_child] < array[child]) {
            child = right_child;
        }
        if (array[Parent] > array[child]) {
            swap(array[Parent], array[child]);
            Heapify_down(child);
        }

    }

    /**
     * @brief Removes the minimum element (root) from the heap.
     * @note Time Complexity: O(Log n)
     */
    void pop() { // O(Log n)
        assert(!isEmpty());

        array[0] = array[--size];

        Heapify_down(0);

    }

    /**
     * @brief Destructor to free the dynamically allocated memory.
     */
    ~MinHeap() {
        delete[]  array;
        array = nullptr;
    }
};

int main() {
    MinHeap heap;

    // Testing push operations (Inserting elements out of order)
    cout << "--- Inserting Elements: 40, 10, 30, 5, 15 ---" << endl;
    heap.push(40);
    heap.push(10);
    heap.push(30);
    heap.push(5);
    heap.push(15);

    // Testing top operation (Should return the minimum element, which is 5)
    cout << "Current minimum (top): " << heap.top() << " (Expected: 5)" << endl;

    // Testing pop operation and checking the next minimums
    cout << "\n--- Popping elements one by one (Should print in sorted order) ---" << endl;

    while (!heap.isEmpty()) {
        cout << "Popping: " << heap.top() << endl;
        heap.pop();
    }

    // Checking if heap is empty after all pops
    if (heap.isEmpty()) {
        cout << "\nHeap is now empty!" << endl;
    }

    return 0;
}