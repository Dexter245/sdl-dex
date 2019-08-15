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

        struct {
            InputVector orientation[3];
        } typedef OrientationVector;

        struct {
            float ampLow = 0.0f;
            float freqLow = 160.0f;
            float ampHigh = 0.0f;
            float freqHigh = 320.0f;
        } typedef VibrationData;

    private:
#ifdef SWITCH
        //sixaxis
        u32 handles[4];
        SixAxisSensorValues sixaxis;
        void getValuesFromSwitch();

        //vibration
        u32 vibrationDeviceHandles[2][2];
        HidVibrationValue vibrationValues[2];
        HidVibrationValue vibrationValue;
        HidVibrationValue vibrationValueStop;
#endif

    public:
        InputEventHandler();

        ~InputEventHandler();

        void update();

        InputVector getAccelerometer();

        InputVector getGyroscope();

        OrientationVector getOrientation();

        void setVibration(VibrationData &vibrationData);

        void stopVibration();


    };

}

#endif