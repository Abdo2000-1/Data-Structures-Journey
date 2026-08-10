    // Abdo Al Adawy 
    #include <iostream>
    #include <vector>
    #include <cassert> // for assert function

    using namespace std;


    // Circular array-based Deque implementation;

    class Deque {

    private:
        int* arr{ };
        int front{ 0 };
        int rear{ 0 };
        int capacity{ };
        int added_elements{ };

    public:
        Deque(int size) : capacity(size), rear(0), front(0), added_elements(0) {

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

        int Prev(int idx)
        {
            if (idx == 0)
            {
                return capacity - 1 ; 
            }
            return idx - 1;
        }

        bool isEmpty()
        {
            return added_elements == 0;
        }
        bool isFull() const {
            return added_elements == capacity;
        }

        void enqueue_rear(int value)
        {
            assert(!isFull());

            arr[rear] = value;
            rear = next(rear);
            added_elements++;
        }
        void enqueue_front(int value)
        {
            assert(!isFull());

            front = Prev(front);
            arr[front] = value;
            added_elements++;
        }

        int dequeue_front()
        {
            assert(!isEmpty());

            int removedValue = arr[front];
            front = next(front);
            --added_elements;
            return removedValue;
        }
        int dequeue_rear()
        {
            assert(!isEmpty());

            rear = Prev(rear);
            int removedValue = arr[rear];
            --added_elements;
            return removedValue;
        }


        void display()
        {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return;
            }

            for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
            {
                cout << arr[cur] << " ";
            }
            cout << endl;
        }

        ~Deque()
        {

            delete[] arr;
        }

    };



    int main() {

        Deque dq(6);

        dq.enqueue_front(3);
        dq.enqueue_front(2);
        dq.enqueue_rear(4);
        dq.enqueue_front(1);
        dq.display(); // 1 2 3 4
        cout << dq.dequeue_rear() << "\n"; //4
        dq.display();// 1 2 3 
        cout << dq.dequeue_front() << "\n"; // 1
        dq.display(); // 2 3
        cout << dq.dequeue_rear() << "\n"; // 3
        cout << dq.dequeue_front() << "\n"; // 2
        dq.enqueue_rear(7);
        dq.display(); // 7


        return 0;
    }
