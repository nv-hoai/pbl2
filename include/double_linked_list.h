#pragma once

#include <iostream>
#include <exception>

template <typename T>
class DoublyLinkedList {
public:
    // Node structure
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    // Constructor
    DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) {
        copy(other);
    }

    // Move constructor
    DoublyLinkedList(DoublyLinkedList&& other) noexcept {
        move(other);
    }

    // Copy assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

    // Move assignment operator
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            move(other);
        }
        return *this;
    }

    // Add element at the beginning
    void push_front(const T& element) {
        Node* newNode = new Node{element, nullptr, head_};
        if (head_) {
            head_->prev = newNode;
        } else {
            tail_ = newNode;
        }
        head_ = newNode;
        size_++;
    }

    // Add element at the end
    void push_back(const T& element) {
        Node* newNode = new Node{element, tail_, nullptr};
        if (tail_) {
            tail_->next = newNode;
        } else {
            head_ = newNode;
        }
        tail_ = newNode;
        size_++;
    }

    // Remove element at the beginning
    void pop_front() {
        if (head_) {
            Node* oldHead = head_;
            head_ = head_->next;
            if (head_) {
                head_->prev = nullptr;
            } else {
                tail_ = nullptr;
            }
            delete oldHead;
            size_--;
        } else {
            throw std::runtime_error("List is empty");
        }
    }

    // Remove element at the end
    void pop_back() {
        if (tail_) {
            Node* oldTail = tail_;
            tail_ = tail_->prev;
            if (tail_) {
                tail_->next = nullptr;
            } else {
                head_ = nullptr;
            }
            delete oldTail;
            size_--;
        } else {
            throw std::runtime_error("List is empty");
        }
    }

    //Insert an element
    void insert(const T& element, Node* after) {
        if (!after) {
            // Insert at the end
            push_back(element);
            return;
        }

        Node* newNode = new Node{element, after, after->next};
        if (after->next) {
            after->next->prev = newNode;
        } else {
            tail_ = newNode;
        }
        after->next = newNode;
        size_++;
    }

    //Search for an element
    Node* search(const T& element) {
        Node* current = head_;
        while (current) {
            if (current->data == element) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    //Remove an element from the list
    void remove(Node* node) {
        if (!node) {
            return;
        }

        if (node == head_) {
            pop_front();
        } else if (node == tail_) {
            pop_back();
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            size_--;
        }
    }

    //Display all elements in the list
    void display() {
        Node* current = head_;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Get the size of the list
    int size() const {
        return size_;
    }

    //Get the head node
    Node *head() const {
        return head_;
    }

    //Get the tail node
    Node *tail() const {
        return tail_;
    }

    // Check if the list is empty
    bool empty() const {
        return size_ == 0;
    }

    // Clear the list
    void clear() {
        while (head_) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        tail_ = nullptr;
        size_ = 0;
    }

private:
    Node* head_;
    Node* tail_;
    int size_;

    void copy(const DoublyLinkedList& other) {
        if (other.empty()) {
            return;
        }

        head_ = new Node{other.head_->data, nullptr, nullptr};
        tail_ = head_;
        Node* current = other.head_->next;
        while (current) {
            Node* newNode = new Node{current->data, tail_, nullptr};
            tail_->next = newNode;
            tail_ = newNode;
            current = current->next;
        }
        size_ = other.size_;
    }

    void move(DoublyLinkedList&& other) {
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
};