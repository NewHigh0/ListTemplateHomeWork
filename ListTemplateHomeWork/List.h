#pragma once

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List();
    ~List();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    T& back() const;
    T& front() const;
    void clear();
    bool empty() const;

    int find(const T& value) const;
    void erase(int position);
    void reverse();

};
