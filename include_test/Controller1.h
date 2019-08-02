#ifndef CONTROLLER1_H_
#define CONTROLLER1_H_

#include "Controller.h"
#include "Model1.h"
#include "EventHandler.h"
#include "Application.h"

class Controller1 : public dex::Controller {

private:
    Model1 *model;

    void handleEvents() override;

public:
    explicit Controller1(Model1 *model);

    ~Controller1() override;

    void update(float delta) override;

};


#endif