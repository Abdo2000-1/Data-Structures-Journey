// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

struct Node {
    int data{ };
    Node* next{ nullptr };

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head{ nullptr };
    Node* tail{ nullptr };
    int length{ 0 };

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void insert_end(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++length;
    }
    // Problem #2
    void insert_front(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        ++length;
    }

    // Problem #3
    void delete_front() {
        assert(head != nullptr);

        Node* temp = head;
        head = head->next;
        delete temp;

        if (!head) {
            tail = nullptr;
        }
        --length;
    }

    Node* get_nth(int n) 
    {
        int cnt = 0;
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n)
                return cur;

        return nullptr;
    }
    // Problem #4 Get nth from back

    Node* get_nth_back(int n) const {
           

        if (n < 1 || n > length) {
            return nullptr;
        }

        int nth_back = length - n + 1;


        Node* cur = head;

        for (int i = 1; i < nth_back; ++i) {
            cur = cur->next;
        }
        return cur;
      
       
        
       
    }

    void Print_get_nth_back(int n , const LinkedList& list)
    {
        Node* res = list.get_nth_back(n);
        if (res != nullptr) {
            cout << res->data << endl;
        }
        else {
            cout << "Out of bounds!" << endl;
        }
    }

    // Problem # 5  Is Same list’s data

    // First Method
    bool is_same(const LinkedList &other) 
    {

        if (other.length == length) 
        {       
            Node* cur1 = head;
            Node* cur2 = other.head;

            for (int i = 0; i < length; ++i) 
            {
                if (cur1->data != cur2->data)
                {
                    return false;
                }
                else 
                {
                    cur1 = cur1->next;
                    cur2 = cur2->next;

                }
            }
            return true;
        
        }
        return false;

    }


    bool is_same_without_length(const LinkedList& other)
    {
        Node* cur1 = head;
        Node* cur2 = other.head;

        while (cur1 && cur2)
        {
            if (cur1->data != cur2->data)
            {
                return false;
            }
            else 
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }

        }
        if (cur1 == cur2 ) {
            return true;
        }
        return false;
       
    }

    void print() {
        for (Node* cur = head; cur ; cur = cur->next) {
            cout << cur->data << " -> ";
        }
        cout << "nullptr" << endl;
    }

    int size() {
        return length;
    }







    // Problem #1
    ~LinkedList() {
        while (head) {
            delete_front();
        }
    }
};

int main() {
    LinkedList list1;

    list1.insert_end(10);
    list1.insert_end(20);
    list1.insert_end(30);
    list1.insert_front(5);
    list1.insert_front(1);

    cout << "Original List 1: ";
    list1.print();

    cout << "Size: " << list1.size() << endl;
    cout << "---------------------------------------" << endl;

    list1.delete_front();
    cout << "After delete_front: ";
    list1.print();
    cout << "Size: " << list1.size() << endl;
    cout << "---------------------------------------" << endl;

    Node* nth = list1.get_nth(2);
    if (nth) {
        cout << "2nd node from front: " << nth->data << endl;
    }
    cout << "---------------------------------------" << endl;

    cout << "1st node from back: ";
    list1.Print_get_nth_back(1,list1);
    cout << "2nd node from back: ";
    list1.Print_get_nth_back(2, list1);
    cout << "---------------------------------------" << endl;

    LinkedList list2;
    list2.insert_end(5);
    list2.insert_end(10);
    list2.insert_end(20);
    list2.insert_end(30);
    cout << "List 2: ";
    list2.print();

    bool same_method1 = list1.is_same(list2);
    cout << "is_same (Method 1): " << same_method1 << endl;

    list2.insert_end(40);
    cout << "List 2 after adding 40: ";
    list2.print();

    bool same_method2 = list1.is_same_without_length(list2);
    cout << "is_same (Method 2): " << same_method2 << endl;
    cout << "---------------------------------------" << endl;
    return 0;
}
       