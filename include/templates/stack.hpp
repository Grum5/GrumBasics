#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>

template <typename T>
class Stack {
    /*
     * Stack template
     */

public:
    // Constructors
    Stack();
    Stack(const T& data);
 
    // Deconstructor
    ~Stack();

    // Methods
    void print() const;
    void add(const T& data);
    void pop();
    void clear();
    bool empty() const;
    void top() const;
    int size() const;

private:
    // Node Struct
    struct Node {
        T data;
        Node* next;
    };

    // Attributtes
    Node* Top;

};


// - Constructors --------------------------------------------------------------------------

template <typename T>
Stack<T>::Stack() {
    /* Empty stack constructor */

    Top = nullptr;
}

template <typename T>
Stack<T>::Stack(const T& data) {
    /* No empty stack constructor */

    Top = new Node;
    Top->data = data;
    Top->next = nullptr;
}

// - Deconstructors ------------------------------------------------------------------------

template <typename T>
Stack<T>::~Stack() {
    /* Deconstructor */

    // Create a temporal pointer of Node, to delete it
    Node* to_delete = nullptr;

    // Delete all the nodes of the stack, until Top becomes nullptr
    while (Top != nullptr) {
        to_delete = Top;
        Top = Top->next;
        delete to_delete;
    }
}

// - Methods ------------------------------------------------------------------------------

template <typename T>
void Stack<T>::print() const {
    /* Method that prints the Stack, from top to bottom */

    // Temporal pointer to print the complete stack
    Node* current = Top;

    // Expected output on CLI: (x1, x2, x3 ... xn)
    std::cout << "(";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << ")" << std::endl;
}

template <typename T>
void Stack<T>::add(const T& data) {
    /* Method that add a node to the top of the stack */

    // Create a new node with the data and the reference to Top
    Node* new_node = new Node{data, Top};

    // Top becomes the new node
    Top = new_node;
}

template <typename T>
void Stack<T>::pop() {
    /* Method that pop the top node of the stack */

    // If the stack its empty then exit the method
    if (Top == nullptr) return;

    // Create a temporal pointer of Node that points to the top to delete it
    Node* to_delete = Top;

    // Move the top node to the next node
    Top = Top->next;

    // Delete (Pop) the top node
    delete to_delete;
}

template <typename T>
void Stack<T>::clear() {
    /* Method to clear the complete stack */
    
    // if the stack its empty then exit the method
    if (Top == nullptr) return;

    // Temporal pointer to delete the node
    Node* to_delete = nullptr;
    
    while (Top != nullptr) {
        to_delete = Top;
        Top = Top->next;
        delete to_delete;
    }
}

template <typename T>
bool Stack<T>::empty() const {
    /* Method that return a boolean, if the stack its empty return true, else false */

    if (Top == nullptr) {
        return true;
    }
    return false;

}

template <typename T>
void Stack<T>::top() const {
    /* Method to print the top item of the stack, this method doesnt pop the top item */

    // If the stack its empty, exit
    if (Top == nullptr) {
        std::cerr << "Error: Attempt to access top of empty stack!" << std::endl;
        return;
    }

    std::cout << Top->data << std::endl;
}

template <typename T>
int Stack<T>::size() const {
    /* Method that returns the size of the stack */

    if (Top == nullptr) return 0;
    
    int counter = 0;
    Node* current = Top;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }
    return counter;
}

#endif // STACK_HPP_
