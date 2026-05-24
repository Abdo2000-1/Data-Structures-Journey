// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> 
// Linked List Without neither tail nor length 
using namespace std;

struct Node {
    int data{ };
    Node* next{ nullptr };

    Node(int value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head{ nullptr };
  

public:
    LinkedList() : head(nullptr){}





    void add_element(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
           newNode->next = head;
           head = newNode;
        }
    }

    Node* get_tail()
    {
        if (!head) 
        { 
            return nullptr;
        }

        Node* cur = head;
        while (cur->next)
        {
           cur = cur->next;

           
        }
        return cur;
   
    }

    void print()
    {
        for (Node* cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " -> ";

        }
        cout << "nullptr\n";
    }


};

int main() 
{
    LinkedList list;
    
    list.add_element(1);
    list.add_element(2);
    list.add_element(3);
    list.add_element(4);
    cout << "\n-----------------------\n";
    Node* tailNode = list.get_tail();
    cout  << tailNode->data;
  
    cout << "\n-----------------------\n";
    list.print();

    return 0;
}
       