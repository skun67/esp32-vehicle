#include <Arduino.h>
#include <Wire.h>
#include "Sensors/Imu.h"

void setup() {
    Serial.begin(115200);
    Wire.begin();

    setupImu();
}

void loop() {
    loopImu();
}