
#pragma once

#include <iostream>

class Deque {
    int capacity;
    int *mem;
    int elements;

    int first;


public:

    Deque():                                                   
            capacity(10),                                  
            mem(new int[capacity]),                   
            elements(0),                                   

            first(0)                                   
    {}

    ~Deque(){                       
        delete [] mem;
    }



    Deque(const Deque &ori)     
    {
        capacity=ori.capacity;
        mem=ori.mem;
        elements=ori.elements;
        first=ori.first;

    }


    Deque &operator=(Deque cpy){    
        capacity=cpy.capacity;
        elements=cpy.elements;
        std::swap(mem,cpy.mem);
        return *this;
    }


    void push_back(int x) {
        if (capacity == elements) {
            int *tmp = new int[capacity * 2];

            for(int i=0;i<capacity;i++){   
                tmp[i]=mem[i];
            }

            delete [] mem;
            mem = tmp;
            capacity *=2;  

            first =0;   


        }
        int insertion_location = (first + elements) % capacity;

        mem[insertion_location] = x;

        elements++;

    }

    void push_front(int x){
        if ( capacity==elements) {
            int *tmp = new int[capacity * 2];

            for(int i=0;i<capacity;i++){
                tmp[i]=mem[i];
            }

            delete [] mem;
            mem = tmp;
            capacity *=2;

            first =0;
        }

        elements++;

        int temp;
        for(int i=0;i<(capacity-1);i++){
            temp=mem[capacity-1];
            mem[capacity-1]=mem[i];
            mem[i]=temp;
        }

        mem[0] = x;

    }

    bool empty(){
        if(elements==0)
            return true;
        return false;
    }


void pop_front() {
    if(empty())
        throw std::runtime_error("pop_front() called on an empty stack");

    first = (first + 1) % capacity;
    elements--;
}


    void pop_back(){
        if(empty())
            throw std::runtime_error("pop_back() called on an empty stack");

        elements--;
    }

    int front() {
        if(empty())
            throw std::runtime_error("front called on an empty stack");

        return mem[first];
    }

    int back(){
        if(empty())
            throw std::runtime_error("back called on an empty stack");

        return mem[elements-1];
    }

    int &operator[](int x) {
        return mem[x];
    }

    int size(){
        return capacity;
    }


};
