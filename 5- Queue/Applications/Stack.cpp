 // Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> // for assert function
#include "Queue.h"
using namespace std;

// Staack Implementation Using Queue Delegation

/*
----------------------------------------------------------------------
Execution Flow Chart :
----------------------------------------------------------------------
[User] --->Stack::push()  --->Queue::enqueu() --->LinkedList::insert_end()
[User] --->Stack::pop()   --->Queue::dequeu() --->LinkedList::delete_Last()
[User] --->Stack::peek()  --->Queue::lastIn()  --->LinkedList::Lastin()
======================================================================
*/



    class Stack {

    private:
        Queue q;
        int added_elements{ };

    public:
        Stack() : added_elements(0) {};

      
  
        void push(int value)
        {
    
            q.enqueu(value);
            added_elements++;
        }
        
        int peek() {
            return q.lastIn();
        }
       
        int pop()
        {
            assert(!isEmpty());

            --added_elements;
           return q.dequeu();
      
        }
       
        bool isEmpty()
        {
            return added_elements == 0;
        }

        ~Stack()
        {
            while (!isEmpty()) {
                pop();
          }
          
        }

    };



    int main() {

        Stack stk;
        stk.push(10);
        stk.push(20);
        stk.push(30);

        while (!stk.isEmpty()) {
            cout << stk.peek() << " ";
            stk.pop();
        } // 30 20 10

        return 0;
    }