#pragma once
#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList {
private:
    // Node structure
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    // Iterator class
    class Iterator {
    private:
        Node* current;

        friend class DoublyLinkedList<T>;
    public:
        Iterator(Node* node) : current(node) {}

        // Overload dereference operator
        T& operator*() const {
            return current->data;
        }

        // Overload prefix increment operator
        Iterator& operator++() {
            if (current != nullptr)
                current = current->next;
            return *this;
        }

        // Overload prefix decrement operator
        Iterator& operator--() {
            if (current != nullptr)
                current = current->prev;
            return *this;
        }

        // Overload equality operator
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        // Overload inequality operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Append to the end of the list
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {  // List is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Prepend to the beginning of the list
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {  // List is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Find a value in the list
    Iterator find(const T& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return Iterator(current);
            current = current->next;
        }
        return end();
    }

    // Get iterator to the beginning of the list
    Iterator begin() {
        return Iterator(head);
    }

    // Get iterator to the end (nullptr) of the list
    Iterator end() {
        return Iterator(nullptr);
    }

    // Delete a node
    void deleteNode(Iterator it) {
        Node* delNode = it.current;
        if (delNode == nullptr) return;

        if (delNode == head)
            head = delNode->next;

        if (delNode == tail)
            tail = delNode->prev;

        if (delNode->next != nullptr)
            delNode->next->prev = delNode->prev;

        if (delNode->prev != nullptr)
            delNode->prev->next = delNode->next;

        delete delNode;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
