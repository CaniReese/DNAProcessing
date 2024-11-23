/**
* @file main.cpp
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/
#include "Population.h"
#include <iostream>
#include <fstream>
#include <string>

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Display Population\n";
    std::cout << "2. Crossover\n";
    std::cout << "3. Mutate\n";
    std::cout << "4. Process Automatic Instructions\n";
    std::cout << "5. Display Smallest Genes\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void loadPopulation(Population& population, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error(filename + " file could not be opened!");
    }

    std::string line;
    while (std::getline(file, line)) {
        LinkedList chromosome;
        for (char c : line) {
            if (c != ' ') {
                chromosome.add(c);
            }
        }
        population.addChromosome(chromosome);
    }
    file.close();
}

int main() {
    Population population;

    try {
        loadPopulation(population, "Dna.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:  
                population.display();
                break;

            case 2: {
                int index1, index2;
                std::cout << "Enter two chromosome indices for crossover: ";
                std::cin >> index1 >> index2;

                try {
                    population.crossover(index1, index2);
                    std::cout << "After Crossover:\n";
                    population.display();
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }

            case 3: {  
                int chromosomeIndex, geneIndex;
                std::cout << "Enter chromosome index and gene index to mutate: ";
                std::cin >> chromosomeIndex >> geneIndex;

                try {
                    population.mutate(chromosomeIndex, geneIndex);
                    std::cout << "After Mutation:\n";
                    population.display();
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }

            case 4: {  
                try {
                    population.processInstructions("Islemler.txt");
                    std::cout << "After Automatic Instructions:\n";
                    population.display();
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }

            case 5:  
                population.displaySmallestFromRight();
                break;

            case 6:  
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
