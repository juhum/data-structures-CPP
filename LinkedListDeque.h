#pragma once

#include <iostream>
#include <stdexcept>

struct Node {
    int value;
    Node *next;
    Node *prev;

    Node(int v) :
        value(v),
        next(nullptr),
        prev(nullptr) {}
};

class Deque {
    Node *head;
    Node *tail;
public:
    
    Deque() :
        head(nullptr),
        tail(nullptr)
    {};

    
    Deque(const Deque& other) :
        head(nullptr),
        tail(nullptr)
    {
        Node* tmp = other.head;
        while (tmp != nullptr) {
            push_back(tmp->value);
            tmp = tmp->next;
        }
    }

    
    Deque& operator=(Deque other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        return *this;
    }

    
    ~Deque() {
        while (!empty())
            pop_front();
    }

    int back() const {
        if (tail == nullptr)
            throw std::runtime_error("back called on empty deque");

        return tail->value;
    }

    int front() const {
        if (empty())
            throw std::runtime_error("front called on empty deque");

        return head->value;
    }

    void push_back(int x) {
        if (empty()) {
            head = new Node(x);
            tail = head;
        }
        else {
            Node* tmp = new Node(x);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }

    void push_front(int x) {
        if (empty()) {
            head = new Node(x);
            tail = head;
        }
        else {
            Node* tmp = new Node(x);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }

    void pop_back() {
        if (empty())
            throw std::runtime_error("pop_back called on an empty deque");

        if (tail == head) {
            delete tail;
            head = tail = nullptr;
        }
        else {
            Node* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
        }
    }

    void pop_front() {
        if (empty())
            throw std::runtime_error("pop_front called on an empty deque");

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }
};
