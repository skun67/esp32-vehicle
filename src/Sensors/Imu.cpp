#include <HWCDC.h>

#include "config.h"
#include "MPU9250.h"

MPU9250 mpu;
constexpr unsigned long imuUpdateInterval = 1000;
unsigned long lastUpdateTime;

void printImuData();

void setupImu() {
    while (true) {
        if (mpu.setup(imuAdress))
            break;

        Serial.println("MPU connection failed.");
        delay(5000);
    }
}

void loopImu() {
    if (mpu.update()) {
        unsigned long actualTime = millis();
        if (actualTime >= lastUpdateTime + imuUpdateInterval) {
            lastUpdateTime = actualTime;
            printImuData();
        }
    }
}

void printImuData() {
    Serial.println("IMU data:");

    Serial.print("Yaw, Pitch, Roll [deg]: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);

    Serial.print("Acceleration [mg]: ");
    Serial.print(mpu.getAccX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getAccY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getAccZ(), 2);

    Serial.print("Gyroscope [deg/s]: ");
    Serial.print(mpu.getGyroX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getGyroY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getGyroZ(), 2);

    Serial.print("Magnetometer [mG]: ");
    Serial.print(mpu.getMagX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getMagY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getMagZ(), 2);

    Serial.print("Linear acceleration [mg]: ");
    Serial.print(mpu.getLinearAccX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getLinearAccY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getLinearAccZ(), 2);

    Serial.print("Quaternion [x, y, z, w]: ");
    Serial.print(mpu.getQuaternionX(), 4);
    Serial.print(", ");
    Serial.print(mpu.getQuaternionY(), 4);
    Serial.print(", ");
    Serial.print(mpu.getQuaternionZ(), 4);
    Serial.print(", ");
    Serial.println(mpu.getQuaternionW(), 4);

    Serial.print("Temperature [C]: ");
    Serial.println(mpu.getTemperature(), 2);
}