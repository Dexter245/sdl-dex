#include "Controller1.h"
#include <iostream>
#include <Application.h>
#include <Controller1.h>


Controller1::Controller1(Model1 *model) {
    std::cout << "Controller1 constructor" << std::endl;
    this->model = model;
}

Controller1::~Controller1() {

}

void Controller1::update(float delta) {
    std::cout << "Controller1::update" << std::endl;
}


