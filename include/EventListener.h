#ifndef EVENTLISTENER_H_
#define EVENTLISTENER_H_

#include "Event.h"
#include <vector>

namespace dex {

    class EventListener {

    private:
        std::vector<Event> eventQueue = std::vector<Event>();

        virtual void handleEvents() = 0;

    public:
        void addEvent(Event &event);

        bool hasEvent();

        Event& getEvent();
    };

}

#endif