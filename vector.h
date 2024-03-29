#include <iostream>
#include <stdexcept>


class Vector {
    int capacity;
    int elements;
    int *mem;
public:
    Vector():
            capacity(10),
            elements(0),
            mem(new int[capacity])
    {}


    void push_back(int x) {
        if (capacity == elements) { // 1.
            int *tmp = new int[capacity * 2]; // 1.1.

            // 1.2
            for (int i = 0 ; i < capacity ; i++) {
                tmp[i] = mem[i];
            }

            delete [] mem; // 1.3
            mem = tmp; // 1.4
            capacity *= 2; // 1.5
        }

        mem[elements] = x;
        elements++;
    }

    Vector(int cap) {
        capacity=cap;
        elements=0;
        mem=new int[capacity];
    }

    bool empty(){
        if(elements==0)
            return true;
        return false;
    }

    
    void pop_back() {
    if (empty()) {
        throw std::runtime_error("pop() called on an empty vector");
    }
    elements--;
    delete &mem[elements];
    }


    int back() {
        if (empty()) {
            throw std::runtime_error("top() called on an empty stack");
        }
        return mem[elements - 1];
    }

    ~Vector() {
        delete [] mem;
    }

    int size() {
        return capacity;
    }

    int &operator[](int x) {
        return mem[x];
    }
    Vector(const Vector& original):
            capacity(original.capacity),
            elements(original.elements),
            mem(new int[capacity])
    {
        for (int i = 0 ; i < elements ; i++) {
            mem[i] = original.mem[i];
        }
    }
    Vector &operator=(const Vector &original) {
        if (this != &original) { // guard against self assignment
            if (mem != nullptr)
                delete [] mem; // if mem is allocated, delete it
            capacity = original.capacity; // copy fields from the original
            elements = original.elements; // copy fields from the original
            mem = new int[capacity]; // allocate a new array
            for (int i = 0 ; i < elements ; i++) { // copy mem element by element from original
                mem[i] = original.mem[i];
            }
        }
        return *this; // always return a reference
    }

    Vector operator+(const Vector& original){
        Vector tempy(this->elements+original.elements);
        for(int i=0;i<this->elements;i++) {
           tempy.mem[i]=this->mem[i];
           tempy.elements++;
        }

        for(int i=0;i<original.elements;i++){
            tempy.mem[i+this->elements]=original.mem[i];
            tempy.elements++;
        }

                //DO NOT CHANGE THIS

        return tempy;
    }


    int &at(int x){
        if(x>=0 && x<capacity) {
            if (x == mem[x])
                return mem[x];
        }
        else {
            throw std::runtime_error("out_of_range");
        }
    }

    void resize(int x){

        int *tmp = new int[x]; // 1.1.


        if(x>capacity)
        for (int i = 0 ; i < capacity ; i++)
                tmp[i]=mem[i];
        else if(x<capacity)
            for (int i = 0 ; i < x ; i++)
                tmp[i]=mem[i];
        else
            throw std::runtime_error("resizing_into_same_size");
        capacity = x;
        mem = tmp;

    }

};


