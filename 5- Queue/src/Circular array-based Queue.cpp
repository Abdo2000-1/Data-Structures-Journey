// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> // for assert function

using namespace std;


// Circular array-based Queue implementation;

class Queue_Array {

private:
    int* arr{ };
    int front{ 0 };
    int rear{ 0 };
    int capacity{ };
    int added_elements{ };

public:
    Queue_Array(int size) : capacity(size), rear(0), front(0) , added_elements(0){

        arr = new int[size];
    };

    int next(int idx) 
    {
       // return (idx + 1) % capacity; // less efficient 

        
        if (idx == capacity - 1) 
        {
            return 0; // index 0 , if this is the last element 
        }
        return idx + 1;
    }

    bool isEmpty()
    {
        return added_elements == 0;
    }
    bool isFull() const {
        return added_elements == capacity;
    }

    void enqueu(int value)
    {
        assert(!isFull());

        arr[rear] = value;
        rear = next(rear); 
        added_elements++;                                                          
    }
    int dequeu()
    {
        assert(!isEmpty());

        int removedValue = arr[front];
        front = next(front);
        --added_elements;
        return removedValue;
    }


    void display()
    {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int cur = front, step = 0; step < added_elements; ++step , cur = next(cur)) 
        {
            cout << arr[cur] << " ";
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