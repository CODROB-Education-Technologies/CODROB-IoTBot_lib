#ifndef USE_SERVO_H
#define USE_SERVO_H

/*********************************** Servo Motor Sensor ***********************************
 */
#include <ESP32Servo.h>

class ModuleServo
{
public:
    void goAngle(int pin, int angle, int acceleration);

private:
    Servo servoModule; // Create a Servo object for controlling the servo motor
    int currentAngle = 0;
};
#endif // USE_SERVO_H
