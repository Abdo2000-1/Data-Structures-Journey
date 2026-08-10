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
        Node* prev{ };

        int data{ };
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
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
                
                else
                {
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = newNode;      
                }

                ++length;
            }
 

        int delete_Last() {
            assert(head);

            int removedValue = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            temp->next = nullptr;

            if (!tail) {
                head = nullptr;
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

       int Lastin() 
       {
           return tail->data;
       }

       ~LinkedList() {
           while (head) {
               delete_Last();
           }
       }
 
    };




    #endif