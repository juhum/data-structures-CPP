#include <iostream>
#include <stdexcept>
#include <ctime>

struct Item{
    int cost;
    float quantity;
};

struct Node {
    int value;
    int priority;
    Node *next;

    Node(int _value, int _priority, Node *_next=nullptr):
            value(_value),
            priority(_priority),
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

    void push(int x, int p) {
        elements++;
        Node *tmp = new Node(x, p);
        if (empty()) {
            head = tmp;
            tail = tmp;
        }
        else if (p >= head->priority) {
            tmp->next = head;
            head = tmp;
        }
        else if (p <= tail->priority) {
            tail->next = tmp;
            tail = tmp;
        }
        else {
            Node *current = head;
            while (current->next != nullptr && current->next->priority > tmp->priority) {
                current = current->next;
            }
            tmp->next = current->next;
            current->next = tmp;
        }
    }


    bool empty() const {
        return head == nullptr;
    }

    void front() const {
        if (empty()) {
            throw std::runtime_error("front on an empty queue");
        }
        std::cout << head->value << "," << head->priority << std::endl;
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("pop on an empty queue");
        }
        Node *tmp = head;
        head = head->next;
        delete tmp;
        elements--;
        if (elements == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }

    ~Queue() {
        while(!empty())
            pop();
    }

    Queue(const Queue& original):head(nullptr),tail(nullptr),elements(0){
        Node *tmp = original.head;
        while (tmp != nullptr) {
            push(tmp->value, tmp->priority);
            tmp = tmp->next;
        }
    }

    Queue &operator=(Queue cpy) {
        std::swap(cpy.head, head);
        std::swap(cpy.tail, tail);
        std::swap(cpy.elements, elements);
        return *this;
    }
};
