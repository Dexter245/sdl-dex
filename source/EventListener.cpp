#include "EventListener.h"


void dex::EventListener::addEvent(dex::Event &event) {
    eventQueue.push_back(event);
}

bool dex::EventListener::hasEvent() {
    return eventQueue.size() > 0;
}

dex::Event &dex::EventListener::getEvent() {
    Event &e = eventQueue.front();
    eventQueue.erase(eventQueue.begin());
    return e;
}
