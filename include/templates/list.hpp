#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>

template <typename T>
class List {
    
public:

    // Constructor
    List(T data);
    
    // Deconstructor
    ~List();

    // Metodos
    void print() const;
    void append(const T& value);

private:

    struct Node{

        T data;
        struct Node* next;

    };
    Node* Head;

};

template <typename T>
List<T>::List(T data) {
    Head = new Node;
    Head->data = data;
    Head->next = nullptr;
}

template <typename T>
List<T>::~List() {

    Node* current = Head;

    while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }

    Head = nullptr;

}

template <typename T>
void List<T>::print() const {

    for (Node* current = Head; current != nullptr; current = current->next) {
        std::cout << current->data << std:: endl;
    }

}

template <typename T>
void List<T>::append(const T& value) {

    if (Head == nullptr) {
        Head = new Node;
        Head->data = value;
        Head->next = nullptr;
    }
    else {

        Node* current = Head;
        
        while (current->next != nullptr) {
            current = current->next;
        }

        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;
        current->next = new_node;

    }

}


#endif //LIST_HPP_
