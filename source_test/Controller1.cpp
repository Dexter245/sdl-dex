#include "Controller1.h"
#include <iostream>
#include <Application.h>


Controller1::Controller1(Model1 *model) {
    std::cout << "Controller1 constructor" << std::endl;
    this->model = model;
}

void Controller1::update(float delta) {
    std::cout << "Controller1::update" << std::endl;
    dex::Application::instance().end();
}

