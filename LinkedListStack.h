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

class Stack {
    Node *head;
    int elements;
public:
    Stack():
    head(nullptr),
    elements(0)
    {};

    void push(int x) {
        head = new Node(x, head);
        elements++;
    }

    bool empty() const {
        return head == nullptr;
    }

    int top() const {
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
    }

    void clear() {
        while (!empty()) {
            pop_unsafe();
        }
    }

    ~Stack() {
        clear();
    }

    Stack(const Stack& original):head(nullptr) {
        if (!original.empty()) {
            head = new Node(original.head->value);

            Node *src = original.head->next;
            Node *dst = head;

            while (src != nullptr) {
                dst->next = new Node(src->value);

                // move both pointers
                dst = dst->next;
                src = src->next;
            }
            elements=original.elements;
        }
    }

    Stack &operator=(Stack cpy) {
        std::swap(cpy.head, head);
        std::swap(cpy.elements,elements);
        return *this;
    }

    void print(){
        Node *tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->value << ", ";
            tmp = tmp->next;
        }
    }

Stack operator+(int x){
        this->push(x);
        this->elements++;
        return *this;
 }

    void nth(int n) const {
            if(n<elements){
            Node *tmp = head;
            int i = 0;
            for (i = 0; i < n; i++)
                tmp = tmp->next;

            std::cout << i << "value is" << tmp->value << ", ";
            }
            else
                throw std::runtime_error("n_is_higher_than_elements");
    }

    int size(){
        return elements;
    }

private:
    void pop_unsafe() {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        elements--;
    }
};
