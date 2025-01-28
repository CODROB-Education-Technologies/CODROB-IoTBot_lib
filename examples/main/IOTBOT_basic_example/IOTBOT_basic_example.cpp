#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
  iotbot.begin();
  iotbot.playIntro();
}

void loop()
{
  iotbot.testJoystick();
  delay(1000);
  iotbot.testEncoder();
  delay(1000);
  iotbot.testPotentiometer();
  delay(1000);
  iotbot.testButtons();
  delay(1000);
  iotbot.testRelay();
  delay(1000);
  iotbot.testLDR();
  delay(1000);
  iotbot.controlServo(90);
  delay(1000);
}






