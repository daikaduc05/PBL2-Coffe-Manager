#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;  
    int size;   

public:
   
    LinkedList() : head(nullptr), size(0) {}

    
    ~LinkedList() {
        clear();
    }

    
    void addFront(const T& value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        size++;
    }

    void addBack(const T& value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void removeFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

  
    int getSize() const {
        return size;
    }

   
    void clear() {
        while (head) {
            removeFront();
        }
    }

    bool isEmpty() const {
        return head == nullptr; 
    }

    Node* getHead() const {
        return head;    
    }

    void setHead(Node* newHead) {
        head = newHead;
    }

    void decrementSize() {
        size--;
    }

};

#endif 
