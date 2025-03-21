#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>

template <typename T>
class List {
    /*
     * Simple list template
     */
    
public:
    // Constructor
    List();
    List(T data);
    
    // Deconstructor
    ~List();

    // Methods
    void print() const;
    void append(const T& value);
    int size() const;
    void pop(const int index);
    void clear();

protected:
    // Node Struct
    struct Node{
        T data;
        struct Node* next;
    };

    // Attributes
    Node* Head;
    Node* Tail;

};

// - Constructors --------------------------------------------------------------------------

template <typename T>
List<T>::List() {
    /* Empty list constructor */

    Head = nullptr;
    Tail = nullptr;
}

template <typename T>
List<T>::List(T data) {
    /* No empty list constructor */

    Head = new Node;
    Head->data = data;
    Head->next = nullptr;
    Tail = Head;
}

// - Deconstructors ------------------------------------------------------------------------

template <typename T>
List<T>::~List() {
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
void List<T>::print() const {
    /* Method to print the complete list */

    // If the list its empty then exit
    if (Head == nullptr) return;

    // Temporal pointer to print all the nodes of the list
    Node* current = Head;

    // Expected output on CLI: [x1, x2, x3 ... xn]
    std::cout << "[";
    while (current != nullptr) {
        if (current->next != nullptr) {
            std::cout << current->data << ", ";
        }
        else {
            std::cout << current->data;
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void List<T>::append(const T& value) {
    /* Method that add a new item to the end of the list */

    // Create a new node to add to the list
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    // If the list its empty, then the Head turns in the new item
    if (Head == nullptr) {
        Head = new_node;
        Tail = new_node;
    }
    // Otherwise, the new node its added to the end of the list
    else {
        Tail->next = new_node;
        Tail = new_node;
    }
}

template <typename T>
int List<T>::size() const {
    /* Method that returns the size of the list */

    // If the list its empty then return 0
    if (Head == nullptr) return 0;
    
    // Counter to know the size of the list
    int counter = 0;

    // Temporal pointer used to travel the list
    Node* current = Head;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }
    return counter;
}

template <typename T>
void List<T>::pop(const int index) {
    /* Method that pop an item by index */

    int size = this->size();

    // Check if the list its empty
    if (Head == nullptr) {
        std::cerr << "Error: the list is empty, cannot pop an element." << std::endl;
    }

    // Check if the index its on the range of the list
    if (index >= size || index < 0) {
        std::cerr << "Error: The index " << index << " is out of bounds for the list. The valid index range is from 0 to " << size - 1 << " (size: " << size << ")." << std::endl;
        return;
    }

    Node* to_delete = Head;

    // Index is 0
    if (index == 0) {
        Head = Head->next;
    }

    else {
        // Temporal pointer to delete the node
        Node* prev_node = nullptr;
        
        for (int counter = 0; counter != index; counter++) {
            prev_node = to_delete;
            to_delete = to_delete->next;
        }

        // Update Tail if the last node is being deleted
        if (Tail == to_delete) {
            Tail = prev_node;
        }

        prev_node->next = to_delete->next;
    }

    delete to_delete;
}

template <typename T>
void List<T>::clear() {
    /* Method used to empty the list */

    // If the list its empty then exit
    if (Head == nullptr) return;

    // Temporal node pointer to delete it
    Node* current = Head;

    while (Head != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;

    }

    Head = nullptr;
    Tail = nullptr;
}

#endif //LIST_HPP_
