#include "InputEventHandler.h"
#include <iostream>

dex::InputEventHandler::InputEventHandler() {

#ifdef SWITCH
    hidGetSixAxisSensorHandles(&handles[0], 2, CONTROLLER_PLAYER_1, TYPE_JOYCON_PAIR);
    hidGetSixAxisSensorHandles(&handles[2], 1, CONTROLLER_PLAYER_1, TYPE_PROCONTROLLER);
    hidGetSixAxisSensorHandles(&handles[3], 1, CONTROLLER_HANDHELD, TYPE_HANDHELD);
    hidStartSixAxisSensor(handles[0]);
    hidStartSixAxisSensor(handles[1]);
    hidStartSixAxisSensor(handles[2]);
    hidStartSixAxisSensor(handles[3]);
#endif

}

dex::InputEventHandler::~InputEventHandler() {
#ifdef SWITCH
    hidStopSixAxisSensor(handles[0]);
    hidStopSixAxisSensor(handles[1]);
    hidStopSixAxisSensor(handles[2]);
    hidStopSixAxisSensor(handles[3]);
#endif
}

void dex::InputEventHandler::update() {
#ifdef SWITCH
    hidScanInput();
    getValuesFromSwitch();
#endif
}

#ifdef SWITCH
void dex::InputEventHandler::getValuesFromSwitch(){
    hidSixAxisSensorValuesRead(&sixaxis, CONTROLLER_P1_AUTO, 1);
}
#endif

dex::InputEventHandler::InputVector dex::InputEventHandler::getAccelerometer() {
    dex::InputEventHandler::InputVector inputVector;
#ifdef SWITCH
    inputVector.x = sixaxis.accelerometer.x;
    inputVector.y = sixaxis.accelerometer.y;
    inputVector.z = sixaxis.accelerometer.z;
#endif

    return inputVector;
}

dex::InputEventHandler::InputVector dex::InputEventHandler::getGyroscope() {
    dex::InputEventHandler::InputVector inputVector;
#ifdef SWITCH
    inputVector.x = sixaxis.gyroscope.x;
    inputVector.y = sixaxis.gyroscope.y;
    inputVector.z = sixaxis.gyroscope.z;
#endif

    return inputVector;
}

dex::InputEventHandler::OrientationVector dex::InputEventHandler::getOrientation() {
    dex::InputEventHandler::OrientationVector orientationVector;
#ifdef SWITCH
    for(int i = 0; i < 3; i++){
        orientationVector.orientation[i].x = sixaxis.orientation[i].x;
        orientationVector.orientation[i].y = sixaxis.orientation[i].y;
        orientationVector.orientation[i].z = sixaxis.orientation[i].z;
    }
#endif

    return orientationVector;
}

