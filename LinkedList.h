#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    ~LinkedList();

    void AddToHead(T value);
    void AddToTail(T value);
    void InsertAtPosition(T value, int position);
    void DeleteAtPosition(int position);
    int SearchElement(T value);
    int ReplaceElement(T oldValue, T newValue);
    void Reverse();
    void DeleteAll();
    void Show();
};

#endif 
