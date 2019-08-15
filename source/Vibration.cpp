#include "Vibration.h"
#include <cstring>

dex::Vibration::Vibration() {
#ifdef SWITCH
    hidInitializeVibrationDevices(vibrationDeviceHandles[0], 2, CONTROLLER_HANDHELD, TYPE_HANDHELD);
    hidInitializeVibrationDevices(vibrationDeviceHandles[1], 2, CONTROLLER_PLAYER_1, TYPE_JOYCON_PAIR);
    hidPermitVibration(true);

    vibrationValueStop.amp_low = 0.0f;
    vibrationValueStop.freq_low  = 160.0f;
    vibrationValueStop.amp_high = 0.0f;
    vibrationValueStop.freq_high = 320.0f;
#endif
}

void dex::Vibration::setVibration(dex::Vibration::VibrationData &vibrationData) {
#ifdef SWITCH
    vibrationValue.amp_low   = vibrationData.ampLow;
    vibrationValue.freq_low  = vibrationData.freqLow;
    vibrationValue.amp_high  = vibrationData.ampHigh;
    vibrationValue.freq_high = vibrationData.freqHigh;

    memcpy(&vibrationValues[0], &vibrationValue, sizeof(HidVibrationValue));
    memcpy(&vibrationValues[1], &vibrationValue, sizeof(HidVibrationValue));

    hidSendVibrationValues(vibrationDeviceHandles[1], vibrationValues, 2);
#endif
}

void dex::Vibration::stopVibration() {
#ifdef SWITCH
    memcpy(&vibrationValues[0], &vibrationValueStop, sizeof(HidVibrationValue));
    memcpy(&vibrationValues[1], &vibrationValueStop, sizeof(HidVibrationValue));

    hidSendVibrationValues(vibrationDeviceHandles[1], vibrationValues, 2);
#endif
}
