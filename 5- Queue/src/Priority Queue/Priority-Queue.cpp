// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> // for assert function
#include "LinkedList.h"
using namespace std;


// Priority Queue  implementation;



class Queue_SSL {

    LinkedList list; //delegation

  

public:
   


    bool isEmpty()
    {
        return list.size() == 0;
    }
  
    void enqueu(int value , int prio)
    {

        list.insert_end(value, prio);
    }
    int dequeu()
    {
        assert(!isEmpty());
      return  list.delete_front();
    }

    void display()
    {
        list.print();
    }

    ~Queue_SSL()
    {

     
    }

};



int main() {

    Queue_SSL q;

    q.enqueu(10,2);
    q.enqueu(20,5);
    q.enqueu(30,1);

    cout << "Queue elements: ";
    q.display(); 

    cout << "Dequeued: " << q.dequeu() << endl; 

    cout << "Queue elements after dequeue: ";
    q.display(); 



    return 0;
}