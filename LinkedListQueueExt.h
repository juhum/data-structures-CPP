#pragma once


#include <iostream>
#include <stdexcept>
struct Node {
    int value;
    Node *next;

    Node(int _value, Node *_next=nullptr):
            value(_value),
            next(_next)
    {}
};

class Queue {
    Node *head;
    Node *tail;
    int elements;

public:
    Queue():
            head(nullptr),
            tail(nullptr),
            elements(0)
    {};

    void push(int x) {
        if(empty()) {
            head = new Node(x, head);
            tail = head;
        }
        else {
            tail->next = new Node(x);
            tail=tail->next;
        }
        elements++;
    }

    bool empty() const {
        return head == nullptr;
    }

    int front() const {
        if (empty()) {
            throw std::runtime_error("front on an empty stack");
        }
        return head->value;
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("pop on an empty stack");
        }
        Node *tmp = head;
        head = head->next;
        delete tmp;
        elements--;
        if(elements==0){
            head= nullptr;
            tail= nullptr;
        }
    }


    ~Queue() {
        while(!empty())
            pop();
    }

    Queue(const Queue& original):head(nullptr),tail(nullptr),elements(0){
        Node *tmp = original.head;
        while (tmp != nullptr) {
            push(tmp->value);
            tmp = tmp->next;
        }
        elements=original.elements;

    }


    Queue &operator=(Queue cpy) {
        std::swap(cpy.head, head);
        std::swap(cpy.tail,tail);
        std::swap(cpy.elements,elements);
        return *this;
    }

    int last(){
        return tail->value;
    }

    Queue merge(Queue &a, Queue &b) {
        int a_,b_;
        if(!a.empty())
            a_=a.front();
        else
            a_=0;

        if(!b.empty())
            b_=b.front();
        else
            b_=0;

        if (a_ > b_) {
            if(b_!=0)
                push(b_);
            if (!b.empty()) {
                b.pop();
            } else {
                Node *tmp = a.head;
                while (tmp != nullptr) {
                    push(tmp->value);
                    tmp = tmp->next;
                }
                this->elements = a.elements;
            }
        } else if( b_ > a_) {
            if(a_!=0)
                push(a_);
            if (!a.empty()) {
                a.pop();
            } else {
                Node *tmp = b.head;
                while (tmp != nullptr) {
                    push(tmp->value);
                    tmp = tmp->next;
                }
                this->elements = b.elements;

            }
        }


        return *this;
    }


    void extend( Queue a){
        while(!a.empty()){
            push(a.front());
            a.pop();
        }

    }


    void insert_sorted(int x){
       elements++;
        Node *tmp = new Node(x);
        if(empty()){
            head = new Node(x,head);
            tail=head;
        }
        else if(x<=head->value){

                tmp->next = head;
                head = tmp;

        }
        else {
            Node *current = head;

            while (current->next != nullptr  && current->next->value < tmp->value) {
                current = current->next;
            }


           tmp->next = current->next;
           current->next = tmp;

            if(tail->next != nullptr )
                tail=tail->next;



        }

    }



};

