#ifndef VIBRATION_H_
#define VIBRATION_H_

#ifdef SWITCH
#include "switch.h"
#endif

namespace dex{

    class Vibration{

    public:

        struct {
            float ampLow = 0.0f;
            float freqLow = 160.0f;
            float ampHigh = 0.0f;
            float freqHigh = 320.0f;
        } typedef VibrationData;

    private:
#ifdef SWITCH
        u32 vibrationDeviceHandles[2][2];
        HidVibrationValue vibrationValues[2];
        HidVibrationValue vibrationValue;
        HidVibrationValue vibrationValueStop;
#endif

    public:
        Vibration();

        void setVibration(VibrationData &vibrationData);

        void stopVibration();

    };

}

#endif