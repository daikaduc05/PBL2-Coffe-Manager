#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;  
    Node* rear;   
    int size;    

public:
    
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    
    ~Queue() {
        clear();
    }

    
    void enqueue(const T& value) { // day vao
        Node* newNode = new Node{value, nullptr};
        if (!rear) {  
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    
    void dequeue() { // lay ra
        if (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (!front) {  
                rear = nullptr;
            }
        }
    }

    
    T getFront() const { // lay cai dau
        if (front) {
            return front->data;
        }
        throw std::out_of_range("Queue is empty");
    }

    
    int getSize() const {
        return size;
    }

    
    bool isEmpty() const {
        return (size == 0);
    }

    
    void clear() {
        while (front) {
            dequeue();
        }
    }
};

#endif
