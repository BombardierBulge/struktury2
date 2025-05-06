#include <iostream>
#include "random_examples/random_structures.hpp"

void printQueue(const PriorityQueue<int>& pq) {
    PriorityQueue<int> tempQueue = pq;

    std::cout << "Zawartość kolejki: ";
    while (tempQueue.getSize() > 0) {
        std::cout << tempQueue.extractMax() << " ";
    }
    std::cout << std::endl;
}

int main() {
    //Rozmiary struktur
    std::vector<int> sizes = {5000,10000,15000,20000,25000,30000,35000,40000,45000,50000};

    for (int size : sizes) {
        std::cout << "Rozmiar struktury: " << size << std::endl;

        RandomStructures<int> randomStructures(size);

        randomStructures.generateRandomStructure();

        /*int valueToAdd = 42;
        int priorityToAdd = 50;
        for (auto& pq : randomStructures.getCopies()) {
            pq.insert(valueToAdd, priorityToAdd);
        }*/

        const auto& copies = randomStructures.getCopies();
        if (!copies.empty()) {
            std::cout << "Rozmiar pierwszej kopii po dodaniu elementu: " 
                      << copies[0].getSize() << std::endl<<copies[0].findMax() << " " <<std::endl<<copies[1].findMax() << std::endl;
        }

        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}