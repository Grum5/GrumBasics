#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
    /* 
     *  Queue structure template (FIFO - First In, First Out)
     */
public:
    // Constuctor
    Queue();
    Queue(const T& value);

    // Deconstructor
    ~Queue();

    // Methods
    void print() const;
    void enqueue(const T& value);
    T dequeue();
    void clear();
    bool isEmpty() const;
    int size() const;

private:
    // Node Struct
    struct Node {
        T data;
        struct Node* next;
    };

    Node* Head;
    Node* Tail;
    int queue_size;

};

// - Constructors --------------------------------------------------------------------------

template <typename T>
Queue<T>::Queue() {
    /* Empty queue constructor */

    Head = nullptr;
    Tail = nullptr;
    queue_size = 0;
}

template <typename T>
Queue<T>::Queue(const T& value) {
    /* No empty queue constructor */

    Head = new Node;
    Head->data = value;
    Head->next = nullptr;

    Tail = Head;

    queue_size = 1;
}

// - Deconstructors ------------------------------------------------------------------------

template <typename T>
Queue<T>::~Queue() {
    /* Deconstructor */

    // Create a temporal pointer of Node, to delete it
    Node* to_delete = nullptr;

    while (Head != nullptr) {
        to_delete = Head;
        Head = Head->next;
        delete to_delete;
    }
}

// - Methods ------------------------------------------------------------------------------

template <typename T>
void Queue<T>::print() const {
    /* Method to print the complete queue */

    // Temporal pointer to travel through the struct
    Node* current = Head;

    // Expected output on CLI: [x1, x2, x3 ... xn]
    std::cout << "[";
    while (current != nullptr) {

        std::cout << current->data;

        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    /* Method that add an element to the end of the queue */

    // Create a new node to add to the queue
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    // If the queue its empty then the Head and Tail becomes the new item
    if (Head == nullptr) {
        Head = new_node;
        Tail = new_node;
    }
    // Otherwise the queue its not empty, then the item will be add after the Tail
    else {
        Tail->next = new_node;
        Tail = new_node;
    }

    queue_size++;
}

template <typename T>
T Queue<T>::dequeue() {
    /* Method used to dequeue the first element in the queue and return it */

    // Check if the queue is empty and throw an exception if true
    if (Head == nullptr) {
        throw std::out_of_range("Cannot dequeue from an empty queue");
    }

    // Temporary pointer to store the current Head node before deleting it after moving to the next element
    Node* to_delete = Head;

    // Save the value of the Head node to return it
    T value = Head->data;

    // Update the Head pointer to the next element
    Head = Head->next;

    // If the queue becomes empty, update Tail to nullptr as well
    if (Head == nullptr) {
        Tail = nullptr;
    }

    // Delete the old Head node after moving the Head pointer
    delete to_delete;

    queue_size--;

    // Return the value of the dequeued element (previous Head node)
    return value;
}

template <typename T>
void Queue<T>::clear() {
    /* Method used to empty the list */

    // If the list its empty then exit
    if (Head == nullptr) return;

    while (Head != nullptr) {
        Node* to_delete = Head;
        Head = Head->next;
        delete to_delete;

    }

    Tail = nullptr;
    queue_size = 0;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    /* Method to check if the queue is empty (return a boolean) */

    if (Head == nullptr) return true;

    return false;
}

template <typename T>
int Queue<T>::size() const {
    /* Method that return the size of the queue */

    return queue_size;
}

#endif  // QUEUE_HPP_
