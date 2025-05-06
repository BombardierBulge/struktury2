#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node(const T& d, int p) : data(d), priority(p), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    PriorityQueue();
    ~PriorityQueue();
    
    void insert(const T& element, int priority);
    T extractMax();
    T findMax() const;
    void modifyKey(const T& element, int newPriority);
    int getSize() const;

    PriorityQueue(const PriorityQueue& other);
    PriorityQueue& operator=(const PriorityQueue& other);
};

#include "priority_queue.tpp"
#endif
