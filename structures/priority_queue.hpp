#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template <typename T>
class PriorityQueue {
private:
    struct Node {//struktura wezla
        T data;//dane typu T template
        int priority;//priorytet
        Node* next; //wskaźnik na następny node
        Node(const T& d, int p) : data(d), priority(p), next(nullptr) {}//konstruktor
    };
    
    Node* head;
    int size;

public:
    PriorityQueue();//konstruktor
    ~PriorityQueue();//destruktor
    
    void insert(const T& element, int priority);//wstawia element do kolejki z priorytetem
    T extractMax();	//usuwa element o najwyzszym priorytecie i go zwraca
    T findMax() const;	//zwraca element o najwyzszym priorytecie bez usuwania go z kolejki
    void modifyKey(const T& element, int newPriority);	//zmienia priorytet elementu w kolejce o wybranej wartości
    int getSize() const;	//zwraca rozmiar kolejki

    PriorityQueue(const PriorityQueue& other);//konstruktor kopiujący
    PriorityQueue& operator=(const PriorityQueue& other);//operator przypisania
};

#include "priority_queue.tpp"
#endif
