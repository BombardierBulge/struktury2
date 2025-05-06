#include <stdexcept>
#include "priority_queue.hpp"
template <typename T>
PriorityQueue<T>::PriorityQueue() : head(nullptr), size(0) {}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (head) {
        extractMax();
    }
}

template <typename T>
void PriorityQueue<T>::insert(const T& element, int priority) {
    Node* newNode = new Node(element, priority);
    
    if (!head || priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

template <typename T>
T PriorityQueue<T>::extractMax() {
    if (!head) throw std::runtime_error("Queue is empty");
    
    Node* temp = head;
    T max = temp->data;
    head = head->next;
    delete temp;
    size--;
    return max;
}

template <typename T>
T PriorityQueue<T>::findMax() const {
    if (!head) throw std::runtime_error("Queue is empty");
    return head->data;
}

template <typename T>
void PriorityQueue<T>::modifyKey(const T& element, int newPriority) {
    Node* prev = nullptr;
    Node* current = head;
    
    while (current && current->data != element) {
        prev = current;
        current = current->next;
    }
    
    if (!current) throw std::runtime_error("Element not found");
    
    if (prev) {
        prev->next = current->next;
    } else {
        head = current->next;
    }
    size--;
    insert(current->data, newPriority); 
    delete current;
}

template <typename T>
int PriorityQueue<T>::getSize() const {
    return size;
}
