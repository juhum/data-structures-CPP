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
            throw std::runtime_error("top on an empty stack");
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

        }


    Queue &operator=(Queue cpy) {
        std::swap(cpy.head, head);
        std::swap(cpy.tail,tail);
        std::swap(cpy.elements,elements);
        return *this;
    }




};

