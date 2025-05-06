#ifndef PRIORITY_QUEUE_KOPIEC_HPP
#define PRIORITY_QUEUE_KOPIEC_HPP

#include <vector>
#include <stdexcept>

// Szablon klasy kopca priorytetowego
template<typename T>
class PriorityQueueKopiec {
private:
    std::vector<std::pair<int, T>> heap;

    void heapify_up(int index);
    void heapify_down(int index);

public:
    void insert(const T& e, int p);
    T extract_max();
    T peek() const;
    void modify_key(const T& e, int new_p);
    int return_size() const;
    bool empty() const;
};

#include "PriorityQueue_kopiec.tpp"
#endif