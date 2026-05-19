    #pragma once
    #ifndef LINKEDLIST_H
    #define LINKEDLIST_H
    #include<iostream>
    #include<string>
    #include<cassert>
using namespace std;

    struct Node 
    {
        Node* next{ };
 
        int data{ };
        Node(int value) : data(value), next(nullptr){}
    };

    class LinkedList
    {
        Node* head{ nullptr };
        Node* tail{ nullptr };
        int length{ 0 };
    public:

            LinkedList(): length(0), head(nullptr), tail(nullptr){}
    
        void insert_end(int value) 
        {
        
            Node* newNode = new Node(value);

            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;   
                tail = newNode;
           
            }
            ++length;
        }

        int delete_front() {
            assert(head);
         
            int removedValue = head->data;
            Node* temp = head;
            head = head->next;
            
            if (!head) {
                tail = nullptr;
            }

            delete temp;
            --length;

            return removedValue;

        }

        int size() {
          
            return length;
        }

       void print() {
          
            for (Node* cur = head; cur; cur = cur->next)
            { 
                cout << cur->data << " ";

            }
            cout << endl;
        }



       ~LinkedList() {
           while (head) {
               delete_front(); 
           }
       }
 
    };




    #endif