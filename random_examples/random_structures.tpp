#include <random>
#include "random_structures.hpp"

template <typename T>
RandomStructures<T>::RandomStructures(int size, StructureType type) 
    : structureSize(size), structureType(type) {}

template <typename T>
void RandomStructures<T>::generateRandomStructure() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> value(0, structureSize * 3); 
    std::uniform_int_distribution<> priority(0, structureSize * 3);

    if (structureType == StructureType::Queue) {
        std::vector<PriorityQueue<T>> queueCopies;
        PriorityQueue<T> baseQueue;

        for (int j = 0; j < structureSize; ++j) {
            T randomValue = static_cast<T>(value(gen)); 
            int randomPriority = priority(gen);       
            baseQueue.insert(randomValue, randomPriority);
        }

        for (int i = 0; i < 100; ++i) {
            queueCopies.push_back(baseQueue); 
        }

        queueCopies.swap(copiesQueue);
    } else if (structureType == StructureType::Heap) {
        std::vector<PriorityQueueKopiec<T>> heapCopies;
        PriorityQueueKopiec<T> baseHeap;

        for (int j = 0; j < structureSize; ++j) {
            T randomValue = static_cast<T>(value(gen)); 
            int randomPriority = priority(gen);       
            baseHeap.insert(randomValue, randomPriority);
        }

        for (int i = 0; i < 100; ++i) {
            heapCopies.push_back(baseHeap); 
        }

        heapCopies.swap(copiesHeap);
    }
}

template <typename T>
const std::vector<PriorityQueue<T>>& RandomStructures<T>::getQueueCopies() const {
    return copiesQueue;
}

template <typename T>
const std::vector<PriorityQueueKopiec<T>>& RandomStructures<T>::getHeapCopies() const {
    return copiesHeap;
}