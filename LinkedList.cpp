#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    DeleteAll();
}

template <typename T>
void LinkedList<T>::AddToHead(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void LinkedList<T>::AddToTail(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::InsertAtPosition(T value, int position) {
    if (position < 0) {
        std::cerr << "Invalid position\n";
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
        return;
    }

    Node<T>* temp = head;
    for (int i = 0; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        std::cerr << "Invalid position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (!newNode->next) {
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::DeleteAtPosition(int position) {
    if (position < 0 || !head) {
        std::cerr << "Invalid position\n";
        return;
    }

    Node<T>* temp = head;

    if (position == 0) {
        head = head->next;
        delete temp;

        if (!head) {
            tail = nullptr;
        }
        return;
    }

    for (int i = 0; i < position - 1 && temp->next; ++i) {
        temp = temp->next;
    }

    if (!temp->next) {
        std::cerr << "Invalid position\n";
        return;
    }

    Node<T>* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    if (!temp->next) {
        tail = temp;
    }
}

template <typename T>
int LinkedList<T>::SearchElement(T value) {
    Node<T>* temp = head;
    int position = 0;

    while (temp) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        ++position;
    }

    return -1;  
}

template <typename T>
int LinkedList<T>::ReplaceElement(T oldValue, T newValue) {
    Node<T>* temp = head;
    int count = 0;

    while (temp) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            ++count;
        }
        temp = temp->next;
    }

    return count;
}

template <typename T>
void LinkedList<T>::Reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

template <typename T>
void LinkedList<T>::DeleteAll() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::Show() {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


template class LinkedList<int>;
