#include "templates/queue.hpp"
#include <iostream>

int main() {

    Queue<int> cola;

    for(int index = 0; index < 10; index++) {
        cola.enqueue(index);
    }

    cola.print();

    std::cout << cola.dequeue() << std::endl;

    std::cout << "Tamaño: " << cola.size() << std::endl;

    while (!cola.isEmpty()){
        std::cout << cola.dequeue() << std::endl;
    }

    for(int index = 0; index < 10; index++) {
        cola.enqueue(index);
    }
    cola.print();
    cola.clear();
    cola.print();


    return 0;
}

