#ifndef RANDOM_STRUCTURES_HPP
#define RANDOM_STRUCTURES_HPP

#include "../structures/priority_queue.hpp"
#include "../structures/PriorityQueue_kopiec.hpp"
#include <vector>

enum class StructureType {
    Queue,
    Heap
};

template <typename T>
class RandomStructures {
private:
    int structureSize;
    StructureType structureType;
    std::vector<PriorityQueue<T>> copiesQueue;        
    std::vector<PriorityQueueKopiec<T>> copiesHeap;    

public:
    RandomStructures(int size, StructureType type);
    void generateRandomStructure();

    const std::vector<PriorityQueue<T>>& getQueueCopies() const;
    const std::vector<PriorityQueueKopiec<T>>& getHeapCopies() const;
};

#include "random_structures.tpp"
#endif