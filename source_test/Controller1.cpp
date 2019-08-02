#include "Controller1.h"
#include <iostream>
#include <Application.h>
#include <Controller1.h>
#include "Event.h"
#include "EventListener.h"

Controller1::Controller1(Model1 *model) :
        model(model) {
    std::cout << "Controller1 constructor" << std::endl;
    dex::Application::instance().getEventHandler().addEventListener(*this);
}

Controller1::~Controller1() {

}

void Controller1::update(float delta) {
    std::cout << "Controller1::update" << std::endl;

    handleEvents();

}

void Controller1::handleEvents() {
    while (hasEvent()) {
        dex::Event e = getEvent();
        std::cout << "event type: " << e.getType() << ", name: " << e.getName() << std::endl;
        dex::Application::instance().end();
    }

}


