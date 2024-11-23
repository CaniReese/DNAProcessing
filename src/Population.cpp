/**
* @file Population.cpp
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/
#include "Population.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

void Population::addChromosome(const LinkedList& chromosome) {
    chromosomes.push_back(chromosome);
}

void Population::display() {
    for (size_t i = 0; i < chromosomes.size(); ++i) {
        std::cout << "Chromosome " << i << ": ";
        chromosomes[i].display();
    }
}

void Population::crossover(int index1, int index2) {
    if (index1 < 0 || index1 >= chromosomes.size() || index2 < 0 || index2 >= chromosomes.size()) {
        throw std::out_of_range("Invalid chromosome index for crossover!");
    }

    LinkedList& chrom1 = chromosomes[index1];
    LinkedList& chrom2 = chromosomes[index2];

    size_t mid1 = chrom1.size() / 2;
    size_t mid2 = chrom2.size() / 2;

    LinkedList newChromosome1, newChromosome2;

    chrom1.copyLeftHalf(newChromosome1, mid1);
    chrom2.copyRightHalf(newChromosome1, mid2);

    chrom2.copyLeftHalf(newChromosome2, mid2);
    chrom1.copyRightHalf(newChromosome2, mid1);

    addChromosome(newChromosome1);
    addChromosome(newChromosome2);
}
void Population::mutate(int chromosomeIndex, int geneIndex) {
    if (chromosomeIndex < 0 || chromosomeIndex >= chromosomes.size()) {
        throw std::out_of_range("Invalid chromosome index");
    }

    chromosomes[chromosomeIndex].mutate(geneIndex, 'X');
}
void Population::processInstructions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Islemler.txt could not be opened!");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char operation;
        int index1, index2;

        iss >> operation >> index1 >> index2;

        if (operation == 'C') {
            try {
                crossover(index1, index2);
                std::cout << "Crossover completed: " << index1 << " and " << index2 << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Crossover error: " << e.what() << std::endl;
            }
        } else if (operation == 'M') {
            try {
                mutate(index1, index2);
                std::cout << "Mutation completed: Chromosome " << index1 << ", Gene " << index2 << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Mutation error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Invalid operation in file: " << operation << std::endl;
        }
    }
    file.close();
}
void Population::displaySmallestFromRight() {
    for (size_t i = 0; i < chromosomes.size(); ++i) {
        try {
            char smallest = chromosomes[i].findSmallestFromRight();
            std::cout << "Chromosome " << i << ": " << smallest << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error with Chromosome " << i << ": " << e.what() << std::endl;
        }
    }
}
