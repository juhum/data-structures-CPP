
#pragma once

#include <iostream>

class Queue {
    int capacity;
    int *mem;
    int elements;

    int first;
public:

    Queue():                                                   
            capacity(10),                                  
            mem(new int[capacity]),                  
            elements(0),                                   

            first(0)                                        
    {}

    ~Queue(){                       
        delete [] mem;
    }



     Queue(const Queue &ori)     
    {
        capacity=ori.capacity;
        mem=ori.mem;
        elements=ori.elements;
        mem = new int[capacity];
        for (int i = 0 ; i < elements ; i++) {
            mem[i] = ori.mem[i];
        }
        first=ori.first;

    }


      Queue &operator=(const Queue &original){    
        if(this!=&original){
            if(mem != nullptr)
                delete [] mem;

            capacity = original.capacity;
            elements=original.elements;
            mem = new int[capacity];
            for(int i=0;i<elements;i++){
                mem[i]=original.mem[i];
            }
        }
       return *this;
    }



    void push(int x) {
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

    bool empty(){
        if(elements==0)
            return true;
        return false;
    }


    void pop() {        
        if(empty())
            throw std::runtime_error("pop() called on an empty stack");

        first = (first + 1) % capacity;
        elements--;

    }

   int front() {
        if(empty())
            throw std::runtime_error("front called on an empty stack");

        return mem[first];
    }

    int size(){
        return capacity;
    }

    int &operator[](int x) {
        return mem[x];
    }
};

