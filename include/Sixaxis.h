#ifndef SIXAXIS_H_
#define SIXAXIS_H_

#ifdef SWITCH
#include "switch.h"
#endif

namespace dex{

    class Sixaxis{

    public:
        struct {
            float x = 0;
            float y = 0;
            float z = 0;
        } typedef InputVector;

        struct {
            InputVector orientation[3];
        } typedef OrientationVector;


    private:
#ifdef SWITCH
        //sixaxis
        u32 handles[4];
        SixAxisSensorValues sixaxis;
        void getValuesFromSwitch();
#endif

    public:
        Sixaxis();
        ~Sixaxis();

        void update();

        InputVector getAccelerometer();

        InputVector getGyroscope();

        OrientationVector getOrientation();


    };

}

#endif