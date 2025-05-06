#ifndef RANDOM_STRUCTURES_HPP
#define RANDOM_STRUCTURES_HPP

#include "../structures/priority_queue.hpp"
#include <vector>

template <typename T>
class RandomStructures {
private:
    int structureSize;
    std::vector<PriorityQueue<T>> copies;

public:
    RandomStructures(int size);
    void generateRandomStructure();
    const std::vector<PriorityQueue<T>>& getCopies() const;
    std::vector<PriorityQueue<T>>& getCopies();
};

#include "random_structures.tpp"
#endif