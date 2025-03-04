#include "templates/list.hpp"

void testList() {
    List<int> lista(10);
    lista.append(28);
    lista.append(321);
    lista.append(0);
    lista.append(51);

    lista.print();
}

int main(){
    testList();

    return 0;
}
