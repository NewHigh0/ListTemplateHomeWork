#include "List.h"

template class List<int>;

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node(value, nullptr, tail);
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    ++size;
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value, head, nullptr);
    if (head) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
    ++size;
}

template <typename T>
void List<T>::pop_back() {
    Node* oldTail = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete oldTail;
    --size;
}

template <typename T>
void List<T>::pop_front() {
    Node* oldHead = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete oldHead;
    --size;
}

template <typename T>
T& List<T>::back() const {
    return tail->data;
}

template <typename T>
T& List<T>::front() const {
    return head->data;
}

template <typename T>
void List<T>::clear() {
    while (head) {
        pop_front();
    }
}

template <typename T>
bool List<T>::empty() const {
    return size == 0;
}

template <typename T>
int List<T>::find(const T& value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return -1;
}

template <typename T>
void List<T>::erase(int position) {

    Node* current = head;
    int index = 0;

    while (index < position) {
        current = current->next;
        ++index;
    }

    if (current->prev) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    delete current;
    --size;
}

template <typename T>
void List<T>::reverse() {
    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}



