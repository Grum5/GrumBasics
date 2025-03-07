#include "templates/stack.hpp"
#include <iostream>

int main() {

    Stack<int> pila(10);
    pila.add(2);
    pila.add(90);
    pila.add(1);

    pila.print();

    std::cout << pila.size() << std::endl;

    pila.top();

    std::cout << pila.empty() << std::endl;

    pila.pop();

    std::cout << pila.size() << std::endl;

    pila.top();

    pila.print();


    // Testing string
    Stack<std::string> pila2empty;
    Stack<std::string> pila2("hola banda");

    pila2empty.add("wow");
    pila2.add("wow");

    pila2empty.print();
    pila2.print();

    pila2.pop();
    pila2.print();
    return 0;
}
