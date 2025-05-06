
#include "PriorityQueue_kopiec.hpp"
// Naprawa kopca od dołu
template<typename T>
void PriorityQueueKopiec<T>::heapify_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].first > heap[parent].first) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else break;
    }
}

// Naprawa kopca od góry
template<typename T>
void PriorityQueueKopiec<T>::heapify_down(int index) {
    int size = heap.size();
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (heap[left].first > heap[largest].first)
            largest = left;
        if (right < size && heap[right].first > heap[largest].first)
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else break;
    }
}

// insert(e, p)
template<typename T>
void PriorityQueueKopiec<T>::insert(const T& e, int p) {
    heap.push_back({p, e});
    heapify_up(heap.size() - 1);
}

// extract-max()
template<typename T>
T PriorityQueueKopiec<T>::extract_max() {
    if (heap.empty()) throw std::runtime_error("Kopiec jest pusty.");
    T maxElem = heap[0].second;
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(0);
    return maxElem;
}

// peek()
template<typename T>
T PriorityQueueKopiec<T>::peek() const {
    if (heap.empty()) throw std::runtime_error("Kopiec jest pusty.");
    return heap[0].second;
}

// modify-key(e, p)
template<typename T>
void PriorityQueueKopiec<T>::modify_key(const T& e, int new_p) {
    for (std::size_t i = 0; i < heap.size(); ++i) {
        if (heap[i].second == e) {
            int old_p = heap[i].first;
            heap[i].first = new_p;
            if (new_p > old_p)
                heapify_up(i);
            else
                heapify_down(i);
            return;
        }
    }
    throw std::runtime_error("Nie znaleziono elementu do modyfikacji.");
}

// return-size()
template<typename T>
int PriorityQueueKopiec<T>::return_size() const {
    return heap.size();
}

// empty()
template<typename T>
bool PriorityQueueKopiec<T>::empty() const {
    return heap.empty();
}
