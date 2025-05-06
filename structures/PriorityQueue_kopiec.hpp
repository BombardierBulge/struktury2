#pragma once
#include <vector>
#include <string>
#include <stdexcept>

// Szablon klasy kolejki priorytetowej 
template<typename T>
class PriorityQueue {
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
