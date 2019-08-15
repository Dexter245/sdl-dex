#ifndef INPUTEVENTHANDLER_H_
#define INPUTEVENTHANDLER_H_

#ifdef SWITCH
#include "switch.h"
#endif

namespace dex {

    class InputEventHandler {

    public:
        struct {
            float x = 0;
            float y = 0;
            float z = 0;
        } typedef InputVector;

        struct{
            InputVector orientation[3];
        } typedef OrientationVector;

    private:
#ifdef SWITCH
        u32 handles[4];
        SixAxisSensorValues sixaxis;
        void getValuesFromSwitch();
#endif

    public:
        InputEventHandler();
        ~InputEventHandler();
        void update();
        InputVector getAccelerometer();
        InputVector getGyroscope();
        OrientationVector getOrientation();


    };

}

#endif