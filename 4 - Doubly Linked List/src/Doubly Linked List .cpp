#include <iostream>
#include <cassert>
#include <climits>

#include <vector>       // for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
    int data { };
    Node* next { };
    Node* prev { };  // Previous node!

    Node(int data) : data(data) {}

    void set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList {
private:
    Node *head { };
    Node *tail { };
    int length = 0;

public:

    // Below 2 deletes prevent copy and assign to avoid this mistake
    LinkedList() {
    }
    LinkedList(const LinkedList&) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    
    void print() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node* node) {
    
        --length;
        delete node;
    }

    void add_node(Node* node) {
    
        ++length;
    }

    void link(Node* first, Node*second) {
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }

    void insert_end(int value) {
        Node* item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(tail, item);
            tail = item;
        }
    
    }

    void insert_front(int value) {
        Node* item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(item, head);
            head = item;
        }
        
    }

    void print_reversed()  {
        for (Node* cur = tail; cur; cur = cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    void delete_front() {
        if(!head)
            return;
        Node* cur = head->next;
        delete_node(head);
        head = cur;

        // Integrity change
        if(head)
            head->prev = nullptr;
        else if(!length)
            tail = nullptr;

        
    }

    void delete_end() {
        if(!head)
            return;
        Node* cur = tail->prev;
        delete_node(tail);
        tail = cur;

        // Integrity change
        if(tail)
            tail->next = nullptr;
        else if(!length)
            head = nullptr;

        
    }

    Node* delete_and_link(Node* cur) {
        // remove this node, but connect its neighbors
        Node* ret = cur->prev;
        link(cur->prev, cur->next);
        delete_node(cur);

        return ret;
    }

    void delete_node_with_key(int value) {
        if (!length)
            return;
        if (head->data == value)
            delete_front();
        else {
            for (Node *cur = head; cur; cur = cur->next) {
                if (cur->data == value) {
                    cur = delete_and_link(cur);
                    if (!cur->next) // we removed last node!
                        tail = cur;
                    break;
                }
            }
        }
        
    }

    void embed_after(Node* node_before, int value) {
        // Add a node with value between node and its next
        Node* middle= new Node(value);
        ++length;
        

        Node* node_after = node_before->next;
        link(node_before, middle);
        link(middle, node_after);
    }

    void insert_sorted(int value) {     // O(n) time - O(1) memory
        // 3 special cases for simplicity
        if (!length || value <= head->data)
            insert_front(value);
        else if (tail->data <= value)
            insert_end(value);
        else {
            // Find the node I am less than. Then I am before it
            for (Node *cur = head; cur; cur = cur->next) {
                if (value <= cur->data) {
                    embed_after(cur->prev, value);
                    break;
                }
            }
        }
        

        // This idea is used in Insertion Sort Algorithm
    }

//========================================================================================//
  ///////////////////////////// Home Work 1 - 4 Easy ///////////////////////////////////// 
//========================================================================================//

// Problem #1: Delete all nodes with key
    void delete_all_nodes_with_key(int value)
    {
        if (!length)
            return;

        Node *cur = head;
        while (cur) {
            Node *next_node = cur->next; 

            if (cur->data == value) {
                if (cur == head) {
                    delete_front();       // in case of head, we can safely delete it
                } else if (cur == tail) {
                    delete_end();         // in case of tail, we can safely delete it
                } else {
                    delete_and_link(cur); // inbetween node, so we can safely delete it
                }
            }

            cur = next_node; 
        }
    }

// Problem #2: Delete even positions
void delete_even_positions(){


  if (!length)
            return;

            int pos = 1;
        Node *cur = head;
        while (cur) {
            Node *next_node = cur->next; 

            if (pos % 2 == 0) {
                if (cur == tail) {
                    delete_end();         // in case of tail, we can safely delete it
                } else {
                    delete_and_link(cur); // inbetween node, so we can safely delete it
                }
            }

            cur = next_node; 
            pos ++;
        }
    
}


// Problem #3: Delete odd positions
void delete_odd_positions()
{
    if (!length)
            return;

            int pos = 1;
        Node *cur = head;
        while (cur) {
            Node *next_node = cur->next; 

            if (pos % 2 == 1) {
                if (cur == head) {
                    delete_front();       // in case of head, we can safely delete it
                } else if (cur == tail) {
                    delete_end();         // in case of tail, we can safely delete it
                } else {
                    delete_and_link(cur); // inbetween node, so we can safely delete it
                }
            }

            cur = next_node; 
            pos ++;
        }

}

//Problem #4: Is Palindrome
bool is_palindrome()
{
  
    if (!length)
        return true; // An empty list is considered a palindrome

        Node* left = head;
        Node* right = tail;

        for (int i = 0; i < length / 2; ++i , left = left->next, right = right->prev) {

            if (left->data!= right->data)
                return false;
        }

        return true;
}

}; 
void test1()
{
// test delete_all_nodes_with_key
    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(5);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(4);
    list.insert_end(4);
    list.print(); // 1 2 5 4 5 4 4
    cout << "Deleting all nodes with key 5\n";
    list.delete_all_nodes_with_key(5);
    list.print(); // 1 2 4 4 4
}

void test2()
{
    // test delete_even_positions
    LinkedList list;
    list.insert_end(10); // Position 1 (Odd)
    list.insert_end(20); // Position 2 (Even) -> Will be deleted
    list.insert_end(30); // Position 3 (Odd)
    list.insert_end(40); // Position 4 (Even) -> Will be deleted
    list.insert_end(50); // Position 5 (Odd)

    cout << "Original list: ";
    list.print(); // Output: 10 20 30 40 50

    cout << "Deleting even positions...\n";
    list.delete_even_positions();

    cout << "List after deletion: ";
    list.print(); // Expected Output: 10 30 50
}

void test3()
{
    // test delete_odd_positions
    LinkedList list;
    list.insert_end(10); // Position 1 (Odd)  -> Will be deleted
    list.insert_end(20); // Position 2 (Even)
    list.insert_end(30); // Position 3 (Odd)  -> Will be deleted
    list.insert_end(40); // Position 4 (Even)
    list.insert_end(50); // Position 5 (Odd)  -> Will be deleted

    cout << "Original list: ";
    list.print(); // Output: 10 20 30 40 50

    cout << "Deleting odd positions...\n";
    list.delete_odd_positions();

    cout << "List after deletion: ";
    list.print(); // Expected Output: 20 40
}
void test4()
{
    // test is_palindrome
    LinkedList list1;
    list1.insert_end(1);
    list1.insert_end(2);
    list1.insert_end(2);
    list1.insert_end(1);
    cout << "List 1 (1 2 2 1): " << (list1.is_palindrome() ? "True" : "False") << "\n"; // Expected: True

    LinkedList list2;
    list2.insert_end(1);
    list2.insert_end(2);
    list2.insert_end(3);
    list2.insert_end(1);
    cout << "List 2 (1 2 3 1): " << (list2.is_palindrome() ? "True" : "False") << "\n"; // Expected: False

    LinkedList list3;
    list3.insert_end(1);
    cout << "List 3 (1): " << (list3.is_palindrome() ? "True" : "False") << "\n"; // Expected: True
}

int main() {

    test1();
    test2();
    test3();
    test4();

    return 0;
}