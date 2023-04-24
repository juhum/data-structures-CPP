#include <iostream>

struct Node {
    int value;
    Node *next;
    Node *prev;

    explicit Node(int v):
            value(v),
            next(nullptr),
            prev(nullptr)
    {}
};

class DoubleLinkedList {
    Node *head;
    Node *tail;

public:
    DoubleLinkedList():
            head(nullptr),
            tail(nullptr)
    {}

    Node *begin() {
        return head;
    }

    Node *end() {
        return tail;
    }

    bool empty()
    {
        return head == nullptr;
    }

    void clear()
    {
        // write clear
        while(!empty())
            pop_front();
    }

    ~DoubleLinkedList()
    {
        clear();
    }


    void push_back(int x) {
        if(empty()){
            head = new Node(x);
            tail=head;

        }
        else {
            Node *tmp = new Node(x);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }

    void push_front(int x) {
        if(empty())
            throw std::runtime_error("push_front called on empty deque");
        else{
            Node *tmp = new Node(x);
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }

    }

    void pop_back() {
        if(tail == nullptr)
            throw std::runtime_error("pop back called on empty deque");
        else if(tail == head){
            delete tail;
            tail = head = nullptr;
        }
        else{
        Node *tmp = tail;
            tail = tail->prev;
            delete tmp;
    }
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("pop on an empty stack");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
    }

    void insert_before(int x, Node * bef)
    {
        if(x == '\0') {
            push_back(x);
        }
        else {
            Node *tmp = new Node(x);
            bef->prev = tmp;
            tmp->next = bef;
            bef = tmp;
        }
    }

    void remove(Node * x)
    {
        if(empty()) {
            throw std::runtime_error("remove on empty stack");
        }
        else if(x==head) {
            pop_front();
        }
        else if(x==tail){
            pop_back();
        }
        else{
            Node *before = x->prev;
            Node *after = x->next;

            before->next = after;
            after->prev = before;

            delete x;

        }

    }

    Node *find(Node *from, Node *up_to, int value)
    {
        while (from != up_to) {
            if (from->value == value) {
                break;
            }
            from = from->next;
        }

        return from;
    }

    void fill(Node *begin, Node *end, int a)
    {
        while(begin != end){
            begin->value = a;
            begin=begin->next;
        }
        begin->value = a;
        begin=begin->next;

    }

    void fill_n(Node *from, int n, int v)
    {
       for(int i=0;i<n;i++){
           from->value = v;
           from = from->next;
       }

    }

    void iota(Node *begin, Node *end, int v)
    {
        while(begin != end)
        {
            begin->value = v;
            v++;
            begin = begin->next;
        }
        begin->value = v;
        v++;
        begin = begin->next;

    }

    void reverse()
    {
        Node * tmp = head;

        while(tmp!= nullptr) {
            std::swap(tmp->next, tmp->prev);
            tmp = tmp->prev;
        }
        std::swap(head,tail);

    }

    void insert_sorted(int x){
        Node *tmp = new Node(x);
        if(empty()){
            head = new Node(x);
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

            if(tail->next != nullptr ) {
                tail = tail->next;


            }
        }
    }

    int back() {
        if(tail == nullptr)
            throw std::runtime_error("back called on empty deque");

        return tail->value;
    }

    int front() {
        if(empty())
            throw std::runtime_error("front called on empty deque");

        return head->value;
    }



};

