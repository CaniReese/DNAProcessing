/**
* @file Node.h
* @description Bu program, bağlı listeler kullanarak gen, kromozom ve DNA işlemleri gerçekleştirmektedir.
* @course Yüksek Lisans bilimsel hazırlık dersi
* @assignment birinci ödev
* @date 23.11.2024
* @author Mesutcan ÖZKAN mesutcanozkan.20@gmail.com
*/
#ifndef NODE_H
#define NODE_H
class Node {
public:
    char data;          
    Node* next;      
    Node(char data) : data(data), next(nullptr) {}
};
#endif
