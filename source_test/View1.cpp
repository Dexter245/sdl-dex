#include "View1.h"
#include <iostream>


View1::View1(Model1 *model) {
    std::cout << "View1 constructor" << std::endl;
    this->model = model;
}

void View1::render() {
    std::cout << "View1::render" << std::endl;
}
