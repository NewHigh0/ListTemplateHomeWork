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


