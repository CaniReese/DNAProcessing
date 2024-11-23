/**
* @file Population.h
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/
#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include "LinkedList.h"
#include <cstddef>
#include <string>

class Population {
private:
    std::vector<LinkedList> chromosomes;  

public:
    void addChromosome(const LinkedList& chromosome);
    void display();  
    void crossover(int index1, int index2); 
    void mutate(int chromosomeIndex, int geneIndex); 
    void processInstructions(const std::string& filename);
    void displaySmallestFromRight(); 

};

#endif
