#include <iostream>
#include <stdexcept> 

class Stack {
    int capacity;
    int *mem;

    int elements;

public:
    Stack():
            capacity(10),           
            mem(new int[capacity]), 
            elements(0)            
    {
        
    }

    void push(int x) {
        if (capacity == elements) { // 1.
            int *tmp = new int[capacity * 2]; // 1.1.

            
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

        bool empty(){
                if(elements==0)
                return true;

                return false;
    }

        void pop() {
            if (empty()) {
                throw std::runtime_error("pop() called on an empty stack");
            }
            elements--;
    }

        int top() {
            if (empty()) {
                throw std::runtime_error("top() called on an empty stack");
            }

            return mem[elements - 1];
    }

  

    ~Stack() {
        delete [] mem;
    }
};


