/**
* @file LinkedList.h
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <cstddef>

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();

    void add(char data);             
    void display();                  
    size_t size();                   
    void copyLeftHalf(LinkedList& target, size_t mid);  
    void copyRightHalf(LinkedList& target, size_t mid); 
    void mutate(size_t index, char newData); 
    char findSmallestFromRight(); 

};

#endif
