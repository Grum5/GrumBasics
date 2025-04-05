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
    void insert(const T& value, const int index);
    void pop(const int index);
    void clear();
    bool isEmpty() const;

protected:
    // Node Struct
    struct Node{
        T data;
        struct Node* next;
    };

    // Attributes
    Node* Head;
    Node* Tail;
    int list_size;

};

// - Constructors --------------------------------------------------------------------------

template <typename T>
List<T>::List() {
    /* Empty list constructor */

    Head = nullptr;
    Tail = nullptr;
    list_size = 0;
}

template <typename T>
List<T>::List(T data) {
    /* No empty list constructor */

    Head = new Node;
    Head->data = data;
    Head->next = nullptr;

    Tail = Head;

    list_size = 1;
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

    // Temporal pointer to travel through the struct
    Node* current = Head;

    // Expected output on CLI: [x1, x2, x3 ... xn]
    std::cout << "[";
    while (current != nullptr) {

        std::cout << current->data;

        if (current->next != nullptr) {
            std::cout << current->data << ", ";
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

    // If the list its empty, then the Head and Tail turns in the new item
    if (Head == nullptr) {
        Head = new_node;
        Tail = new_node;
    }
    // Otherwise, the new node its added to the end of the list
    else {
        Tail->next = new_node;
        Tail = new_node;
    }

    list_size++;
}

template <typename T>
int List<T>::size() const {

    return list_size;
}

/* FIX */
template <typename T>
void List<T>::insert(const T& value, const int index) {
    /* Method that insert an item by index */
    
    int size = list_size;

    // Check if the list its empty and the index its diferent of 0
    if (Head == nullptr && index != 0) {
        std::cerr << "Error: the list is empty, the index must be 0" << std::endl;
        return;
    }

    // Check if the index its on the range of the list
    if (index > size || index < 0) {
        std::cerr << "Error: The index " << index << " is out of bounds for the list. The valid index range is from 0 to " << size << " (size: " << size << ")." << std::endl;
        return;
    }

    // Create the new node that will be add to the list
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    // Case 1: The item will be add to the first element of the list
    if (index == 0) {
        new_node->next = Head;
        Head = new_node;

        // Check if the Tail its empty, this means that the list was empty and the Tail must be the Head as a first element
        if (Tail == nullptr) {
            Tail = Head;
        }
    }


    list_size++;
}

template <typename T>
void List<T>::pop(const int index) {
    /* Method that pop an item by index */

    int size = list_size;

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

        // Check if the list its empty
        if (Head == nullptr) {
            Tail = nullptr;
        }
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

    list_size--;
    delete to_delete;
}

template <typename T>
void List<T>::clear() {
    /* Method used to empty the list */

    // If the list its empty then exit
    if (Head == nullptr) return;

    while (Head != nullptr) {
        Node* to_delete = Head;
        Head = Head->next;
        delete to_delete;

    }

    Tail = nullptr;
    list_size = 0;
}

template <typename T>
bool List<T>::isEmpty() const {
    /* Method to check if the list is empty (return a boolean) */

    if (Head == nullptr) return true;

    return false;
}

#endif //LIST_HPP_
