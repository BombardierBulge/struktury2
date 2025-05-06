#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <random>
#include "random_examples/random_structures.hpp"
#include "timer/timer.hpp"

void saveResults(const std::string& structureName, const std::string& methodName, int size, double time) {
    std::string directoryPath = "./results/" + structureName + "/" + methodName;
    std::filesystem::create_directories(directoryPath); 

    std::string filePath = directoryPath + "/" + std::to_string(size) + ".txt";
    std::ofstream outFile(filePath, std::ios::app); 
    if (outFile.is_open()) {
        outFile << "Rozmiar: " << size << ", Średni czas: " << time << " \xE6" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Nie można otworzyć pliku: " << filePath << std::endl;
    }
}

int main() {
    int structureSizes[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

    for (int size : structureSizes) {
        //generowanie lista wiazana
        RandomStructures<int> randomQueue(size, StructureType::Queue);
        randomQueue.generateRandomStructure();

        const auto& queueCopies = randomQueue.getQueueCopies();
        if (!queueCopies.empty()) {
            //findMax()
            {
                auto queueCopy = queueCopies; 
                Timer timer;
                timer.reset();
                for (auto& queue : queueCopy) { 
                    queue.findMax();
                }
                timer.stop();
                saveResults("queue", "findMax", size, timer.measurement_micro() / queueCopy.size());
            }

            //getSize()
            {
                auto queueCopy = queueCopies; 
                Timer timer;
                timer.reset();
                for (auto& queue : queueCopy) { 
                    queue.getSize();
                }
                timer.stop();
                saveResults("queue", "getSize", size, timer.measurement_micro() / queueCopy.size());
            }

            //extractMax()
            {
                auto queueCopy = queueCopies; 
                Timer timer;
                timer.reset();
                for (auto& queue : queueCopy) { 
                    queue.extractMax();
                }
                timer.stop();
                saveResults("queue", "extractMax", size, timer.measurement_micro() / queueCopy.size());
            }

            //insert()
            {
                auto queueCopy = queueCopies; 
                Timer timer;
                

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> valueDist(1, queueCopy.size()*3);
                std::uniform_int_distribution<> priorityDist(1, queueCopy.size()*3); 

				timer.reset();

                for (auto& queue : queueCopy) { 
                    int randomValue = valueDist(gen);
                    int randomPriority = priorityDist(gen);
                    queue.insert(randomValue, randomPriority); 
                }
                timer.stop();
                saveResults("queue", "insert", size, timer.measurement_micro() / queueCopy.size());
            }

            //modifyKey()
            {
                auto queueCopy = queueCopies; 
                Timer timer;
                

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> valueDist(1, queueCopy.size()*3); 
                std::uniform_int_distribution<> priorityDist(1, queueCopy.size()*3);

                int successfulOperations = 0;
				timer.reset();
                for (auto& queue : queueCopy) { 
                    int randomValue = valueDist(gen);
                    int randomPriority = priorityDist(gen);

                    try {
                        queue.modifyKey(randomValue, randomPriority); 
                        successfulOperations++; 
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Ostrzeżenie: " << e.what() << std::endl;
                    }
                }

                timer.stop();

                
                if (successfulOperations > 0) {
                    saveResults("queue", "modifyKey", size, timer.measurement_micro() / successfulOperations);
                } else {
                    
                    saveResults("queue", "modifyKey", size, -1);
                }
            }
        }

        //generowanie kopca
        RandomStructures<int> randomHeap(size, StructureType::Heap);
        randomHeap.generateRandomStructure();

        const auto& heapCopies = randomHeap.getHeapCopies();
        if (!heapCopies.empty()) {
            //peek()
            {
                auto heapCopy = heapCopies; 
                Timer timer;
                timer.reset();
                for (auto& heap : heapCopy) { 
                    heap.peek();
                }
                timer.stop();
                saveResults("heap", "peek", size, timer.measurement_micro() / heapCopy.size());
            }

            //return_size()
            {
                auto heapCopy = heapCopies; 
                Timer timer;
                timer.reset();
                for (auto& heap : heapCopy) { 
                    heap.return_size();
                }
                timer.stop();
                saveResults("heap", "return_size", size, timer.measurement_micro() / heapCopy.size());
            }

            //extract_max()
            {
                auto heapCopy = heapCopies; 
                Timer timer;
                timer.reset();
                for (auto& heap : heapCopy) { 
                    heap.extract_max();
                }
                timer.stop();
                saveResults("heap", "extract_max", size, timer.measurement_micro() / heapCopy.size());
            }

			//insert()
			{
				auto heapCopy = heapCopies; 
				Timer timer;
				

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> valueDist(0, heapCopy.size()*3);
				std::uniform_int_distribution<> priorityDist(0, heapCopy.size()*3); 
				timer.reset();
				for (auto& heap : heapCopy) { 
					int randomValue = valueDist(gen);
					int randomPriority = priorityDist(gen);
					heap.insert(randomValue, randomPriority);
				}
				timer.stop();
				saveResults("heap", "insert", size, timer.measurement_micro() / heapCopy.size());
			}

            //modify_key()
            {
                auto heapCopy = heapCopies; 
                Timer timer;
                

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> valueDist(1, heapCopy.size()*3);
                std::uniform_int_distribution<> priorityDist(1, heapCopy.size()*3); 

                int successfulOperations = 0;
				timer.reset();
                for (auto& heap : heapCopy) { 
                    int randomValue = valueDist(gen);
                    int randomPriority = priorityDist(gen);

                    try {
                        heap.modify_key(randomValue, randomPriority); 
                        successfulOperations++; 
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Ostrzeżenie: " << e.what() << std::endl;
                    }
                }

                timer.stop();

                if (successfulOperations > 0) {
                    saveResults("heap", "modify_key", size, timer.measurement_micro() / successfulOperations);
                } else {
                    saveResults("heap", "modify_key", size, -1);
                }
            }
        }
    }

    return 0;
}