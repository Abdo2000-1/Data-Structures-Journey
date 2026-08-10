// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> // for assert function

using namespace std;


//  array-based Queue implementation;

class Queue_Array {

private : 
    int * arr{ };
    int front{ };
    int rear{ };
    int size{ };
    
public:
    Queue_Array(int size) : size(size) , rear(-1), front(-1) {
    
        arr = new int[size];
    };

    bool isEmpty()
    {
        return (rear == -1);
    }
    bool isFull() const {
        return (rear == size - 1);
    }

    void enqueu(int value)
    {
        assert(!isFull());

        if (isEmpty())
            front = 0;

    

        arr[++rear] = value;
    }
    int dequeu()
    {
        assert(!isEmpty());

        int removedValue = arr[front];

        if (front == rear) {

            front = -1;
            rear = -1;
        }
        else {

            front++;
        }


        return removedValue;
    }


    void display() 
    {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue_Array()
    {

        delete[] arr;
    }

};



int main() {

    Queue_Array q(5);

    q.enqueu(10);
    q.enqueu(20);
    q.enqueu(30);

    cout << "Queue elements: ";
    q.display(); 

    cout << "Dequeued: " << q.dequeu() << endl; 

    cout << "Queue elements after dequeue: ";
    q.display(); 
   
   


    return 0;
}