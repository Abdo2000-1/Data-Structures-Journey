// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> // for assert function

using namespace std;


// Stack implementation array based ;

template <typename T>
class Stack_Array
{
private:
    int size{ };
    int top{ };
    T* array{ };

public:
   
    Stack_Array(int size) :size(size), top(-1) {
        array = new T[size];
    }
    // Initialize the stack , 0 based indexing
    
    bool isEmpty() 
    {
        return (top == -1);
    }

    bool isFull() const {
        return (top == size - 1);
    }
    void push(T x)
    {
        assert(!isFull());
        array[++top] = x;
    }

    T pop()
    {
        assert(!isEmpty());
        return array[top--];
    }
    T peek()
    {
        assert(!isEmpty());
        return array[top];
    }


    void display() {
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    ~Stack_Array() 
    {

        delete[] array;
    }
    
};



int main() {

    Stack_Array<int> s(5);
    s.push(10);
    s.push(20);
    s.push(30);
	s.display(); 
	s.pop();
	s.display(); 


    return 0;
}