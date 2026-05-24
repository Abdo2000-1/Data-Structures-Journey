#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string>
#include<cassert>
#include "LinkedList.h"

class Queue {

    LinkedList list; //delegation



public:



    bool isEmpty()
    {
        return list.size() == 0;
    }
    


    void enqueu(int value)
    {
        list.insert_end(value);
    }
    int dequeu()
    {
        assert(!isEmpty());
        return  list.delete_Last();
    }

    void display()
    {
        list.print();
    }

    int lastIn()
    {
        return list.Lastin();
    }

    ~Queue()
    {


    }

};







#endif