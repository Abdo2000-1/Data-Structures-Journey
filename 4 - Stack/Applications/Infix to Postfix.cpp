#include <iostream>
#include <vector>
#include <string>
#include <cassert>


using namespace std;


// SLL-based Stack

struct node
{
    
    node* next{};
    int data;

    node(int value) : data(value) , next(nullptr){};
};


class Stack
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

    ~Stack()
    {
        while (!isEmpty()) {
            pop();
        }

    }
};
///////////////////////////////////////////Postfix////////////////////////////////////////////
int precedence(char op);


// Time O(n) , Every op enter stack once only so is n 
string infixToPostfix(string& infix)
{
    Stack operators;  // of char
    string postfix { };

    infix += '-'; // Whatever lowest priority : Force stack got empty;
    operators.push('#'); // Remove Is Empty : # = 0 always <= any char of the four we have

    for (int i{}; i < (int)infix.size(); ++i) 
    {
        if (isdigit(infix[i])) 
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (operators.peek() != '(') {
                postfix += operators.pop();
            }
            operators.pop();

        }
        else if (infix[i] == '^') { // Right to lef Associativity
            while ((precedence(operators.peek()) > precedence(infix[i])))
            {
                postfix += operators.pop();
            }
            operators.push(infix[i]);
            
        }
        else 
        {
            while ( (precedence(operators.peek()) >= precedence(infix[i]))) 
            {
                postfix += operators.pop();
            } 
            operators.push(infix[i]);
        }
    }
  
    return postfix;


    
}

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;

    else return 0;
     
}

int main() {
   
    string String = "(5+6)*1-(7/5)*(5/8-2)-5^6^8^4-4^2";

    cout << infixToPostfix(String);

    cout << "\n--------------\n";

    return 0;
}