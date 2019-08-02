#include "EventHandler.h"
#include <iostream>

void dex::EventHandler::addEvent(Event event) {
    std::cout << "eventHandler add event" << std::endl;
    for (uint i = 0; i < listeners.size(); i++) {
        listeners[i]->addEvent(event);
    }
}

void dex::EventHandler::addEventListener(dex::EventListener &listener) {
    std::cout << "eventHandler add eventListener" << std::endl;
    listeners.push_back(&listener);
}

