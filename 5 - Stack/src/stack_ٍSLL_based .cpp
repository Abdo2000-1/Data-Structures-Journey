#include <iostream>
#include <vector>
#include <string>
#include <cassert>


using namespace std;


// SLL-based Stack

struct node {
    
    node* next{};
    int data;

    node(int value) : data(value) , next(nullptr){};
};


class Stack_SLL 
{
private:
    node* head{ };

public:


    bool isEmpty() const {
        return !head; // head == nullptr
    }
   
    void push(int value) { 
        node* item = new node(value);
        item->next = head;
        head = item;
    }

    int pop() {
        assert(!isEmpty());
        int element = head->data;
        node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }
    int peek() {
        assert(!isEmpty());
        int top = head->data;
        return top;
    }

    void display() 
    {
        if (isEmpty()) cout << "Stack is Empty\n";
        for (node* cur = head; cur; cur = cur->next)
        {
            cout << "|" << cur->data << "|\n";
           
        }
        
        cout <<"---" << endl;
    }

    ~Stack_SLL()
    {
        while (!isEmpty()) {
            pop();
        }

    }
};


int main() {
   
    Stack_SLL s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    
    cout << "Print Top \n"; 
    cout << s.peek() << endl;// = 5

    s.pop();
    s.pop();
    s.pop();
    cout << "Print Top after Pop \n";
    cout << s.peek() << endl; // = 2

    s.push(20);
    s.push(40);
    s.push(50);

    s.display();


    return 0;
}