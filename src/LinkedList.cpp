/**
* @file LinkedList.cpp
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

void LinkedList::add(char data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

size_t LinkedList::size() {
    size_t count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::copyLeftHalf(LinkedList& target, size_t mid) {
    Node* current = head;
    size_t count = 0;
    while (current != nullptr && count < mid) {
        target.add(current->data);
        current = current->next;
        count++;
    }
}

void LinkedList::copyRightHalf(LinkedList& target, size_t mid) {
    Node* current = head;
    size_t count = 0;
    while (current != nullptr) {
        if (count >= mid) {
            target.add(current->data);
        }
        current = current->next;
        count++;
    }
}

void LinkedList::mutate(size_t index, char newData) {
    Node* current = head;
    size_t count = 0;

    while (current != nullptr) {
        if (count == index) {
            current->data = newData;
            return;
        }
        current = current->next;
        count++;
    }
    throw std::out_of_range("Index out of bounds during mutation");
}
char LinkedList::findSmallestFromRight() {
    if (!head) {
        throw std::runtime_error("Empty chromosome"); 
    }

    Node* current = head;
    char firstGen = head->data;
    char result = firstGen;

   
    while (current != nullptr) {
        if (current->data < firstGen) {
            result = current->data;
            break; 
        }
        current = current->next;
    }
    return result;
}



