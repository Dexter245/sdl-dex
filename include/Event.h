#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>

namespace dex {

    class Event {

    public:
        enum EventType {
            KEY_DOWN,
            KEY_UP,
            BUTTON_DOWN,
            BUTTON_UP
        };

    private:
        EventType type;
        std::string name;

    public:
        Event(EventType type, std::string name);

        EventType getType() { return type; }

        std::string getName() { return name; }

    };

}

#endif