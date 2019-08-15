#ifndef CONTROLLER_H_
#define CONTROLLER_H_

namespace dex {

    class Controller {
    private:

    public:
        virtual void update(float delta) = 0;

        virtual ~Controller() = 0;

    };

}

inline dex::Controller::~Controller() {}

#endif