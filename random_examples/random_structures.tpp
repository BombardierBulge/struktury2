#include <random>
#include "random_structures.hpp"

template <typename T>
RandomStructures<T>::RandomStructures(int size) : structureSize(size) {}

template <typename T>
void RandomStructures<T>::generateRandomStructure() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> value(0, 100000); 
    std::uniform_int_distribution<> priority(0, 100000);
    copies.clear();

    PriorityQueue<T> baseQueue;

    for (int j = 0; j < structureSize; ++j) {
        T randomValue = static_cast<T>(value(gen)); 
        int randomPriority = priority(gen);       
        baseQueue.insert(randomValue, randomPriority);
    }


    for (int i = 0; i < 100; ++i) {
        copies.push_back(baseQueue); 
    }
}

template <typename T>
const std::vector<PriorityQueue<T>>& RandomStructures<T>::getCopies() const {
    return copies;
}

template <typename T>
std::vector<PriorityQueue<T>>& RandomStructures<T>::getCopies() {
    return copies;
}