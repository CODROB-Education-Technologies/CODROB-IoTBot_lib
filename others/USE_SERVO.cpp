/*********************************** Servo Angle Control ***********************************
 * Moves a servo to the specified angle with optional acceleration control.
 * pin: The GPIO pin connected to the servo signal.
 * angle: The target angle for the servo (0° to 180°).
 * acceleration: The delay (in milliseconds) between incremental movements.
 */
#include "USE_SERVO.h"

void ModuleServo::goAngle(int pin, int angle, int acceleration)
{
    // Ensure acceleration is valid
    acceleration = max(acceleration, 1); // Minimum 1 ms gecikme

    // Attach the servo to the specified pin if not already attached
    if (!servoModule.attached())
    {
        servoModule.attach(pin, 1000, 2000); // Sadece bağlı değilse ata
    }

    // Ensure angle is within valid bounds (0 to 180 degrees)
    angle = constrain(angle, 0, 180);

    // Get the current position of the servo
    // int currentAngle = servoModule.read(); // Read the current angle (0° to 180°)

    // Determine movement direction (1 for increasing, -1 for decreasing)
    int step = (angle > currentAngle) ? 1 : -1;

    // Gradually move the servo to the target angle with acceleration
    for (int pos = currentAngle; pos != angle; pos += step)
    {
        servoModule.write(pos); // Move servo to the next position
        delay(acceleration);    // Delay for acceleration control
    }
    currentAngle = angle; // Read the current angle (0° to 180°)

    // Ensure the final angle is set correctly
    servoModule.write(angle);
}
