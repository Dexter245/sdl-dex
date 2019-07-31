#ifndef CONTROLLER_H_
#define CONTROLLER_H_

namespace dex{

    class Controller{
    private:

    public:
        virtual void update(float delta) = 0;
    };

}

#endif