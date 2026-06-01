#pragma once
#ifndef MINHEAP_H 
#define MINHEAP_H

#include <iostream>
#include <vector>
#include <cassert> 
#include <queue> 
#include <string>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    int* array{}; 
    int size{}; 
    int capacity{ 1000 }; 

public:
    MinHeap() {
        array = new int[capacity] {};
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

   
    int sz() {
        return size;
    }

    int left(int node) {
        int p = 2 * node + 1;
        if (p >= size)
            return -1;
        return p;
    }

    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void Heapify_up(int idx) {
        int Parent = parent(idx);
        if (idx == 0 || array[Parent] < array[idx]) return;

        if (array[Parent] > array[idx]) {
            swap(array[idx], array[Parent]);
            Heapify_up(Parent);
        }
    }

    void push(int val) { 
        assert(size + 1 <= capacity);
        array[size++] = val;
        Heapify_up(size - 1);
    }

    int top() {
        assert(!isEmpty());
        return array[0]; 
    }

    void Heapify_down(int Parent) { 
        int child = left(Parent);
        int right_child = right(Parent);

        if (child == -1) return; 

        if (right_child != -1 && array[right_child] < array[child]) {
            child = right_child;
        }
        if (array[Parent] > array[child]) {
            swap(array[Parent], array[child]);
            Heapify_down(child);
        }
    }

    void pop() { 
        assert(!isEmpty());
        array[0] = array[--size];
        Heapify_down(0);
    }

    ~MinHeap() {
        delete[] array;
        array = nullptr;
    }
};

#endif // MINHEAP_H