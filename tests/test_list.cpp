#include "templates/list.hpp"
#include <iostream>

void testList() {
    List<int> lista(10);
    lista.append(28);
    lista.append(321);
    lista.append(0);
    lista.append(51);

    lista.print();
    std::cout << lista.size() << std::endl;

    lista.insert(1000, 3);
    lista.print();
    
}

int main(){
    testList();

    return 0;
}
