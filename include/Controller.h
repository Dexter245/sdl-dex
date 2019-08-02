#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "EventListener.h"

namespace dex {

    class Controller : public dex::EventListener {
    private:

    public:
        virtual void update(float delta) = 0;

        virtual ~Controller() = 0;

//       virtual void handleEvents() = 0;

    };

}

inline dex::Controller::~Controller() {}

#endif