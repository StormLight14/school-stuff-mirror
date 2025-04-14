#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

template<class Type>
struct Node {
    Type data;
    shared_ptr<Node<Type>> next;

    // Default constructor
    Node() : next(nullptr) {}
    Node(Type data, shared_ptr<Node<Type>> next) : data(data), next(next) {}
};

template<class Type>
class Queue {
public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    Queue(const Queue<Type>& q) : front(nullptr), back(nullptr), count(0) {
        if (!q.front) return;
        front = make_shared<Node<Type>>(Node<Type>{q.front->data, nullptr});
        auto current = front;
        auto qCurrent = q.front->next;
        while (qCurrent) {
            current->next = make_shared<Node<Type>>(Node<Type>{qCurrent->data, nullptr});
            current = current->next;
            qCurrent = qCurrent->next;
        }
        back = current;
        count = q.count;
    }

    Queue<Type>& operator=(const Queue<Type>& q) {
        if (this == &q) return *this;
        clear();
        if (!q.front) return *this;
        front = make_shared<Node<Type>>(Node<Type>{q.front->data, nullptr});
        auto current = front;
        auto qCurrent = q.front->next;
        while (qCurrent) {
            current->next = make_shared<Node<Type>>(Node<Type>{qCurrent->data, nullptr});
            current = current->next;
            qCurrent = qCurrent->next;
        }
        back = current;
        count = q.count;
        return *this;
    }

    void enqueue(Type data) {
        auto temp = make_shared<Node<Type>>();
        temp->data = data;
        temp->next = nullptr;
        if (!back) {
            front = temp;
            back = temp;
        } else {
            back->next = temp;
            back = temp;
        }
        count++;
    }

    Type peek() const {
        if (!front) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }

    void dequeue() {
        if (!front) {
            throw runtime_error("Queue is empty");
        }
        front = front->next;
        if (!front) {
            back = nullptr;
        }
        count--;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void clear() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    friend ostream& operator<<(ostream& out, const Queue<Type>& q) {
        auto current = q.front;
        while (current) {
            out << current->data;
            if (current->next) {
                out << " ";
            }
            current = current->next;
        }
        return out;
    }

private:
    shared_ptr<Node<Type>> front;
    shared_ptr<Node<Type>> back;
    int count;
};