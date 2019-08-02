#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include <vector>
#include "Event.h"
#include "EventListener.h"

namespace dex {

    class EventHandler {

    private:
        std::vector<EventListener *> listeners = std::vector<EventListener *>();

    public:
        void addEventListener(EventListener &listener);

        void addEvent(Event event);

    };

}

#endif