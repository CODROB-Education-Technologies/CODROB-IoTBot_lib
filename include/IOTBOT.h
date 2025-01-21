#ifndef IOTBOT_H
#define IOTBOT_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
#include <Encoder.h>

// Pin tanımlamaları
#define JOYSTICK_Y_PIN 15
#define JOYSTICK_X_PIN 34
#define JOYSTICK_BUTTON_PIN 35
#define ENCODER_A_PIN 16
#define ENCODER_B_PIN 17
#define ENCODER_BUTTON_PIN 13
#define BUTTONS_PIN 4
#define BUZZER_PIN 12
#define RELAY_PIN 14
#define LDR_PIN 39
#define POT_PIN 36

#define SERVO_PIN1 25
#define SERVO_PIN2 26

class IOTBOT
{
public:
  IOTBOT();
  void begin();
  void playIntro();
  void testJoystick();
  void testEncoder();
  void testPotentiometer();
  void testButtons();
  void testBuzzer();
  void testRelay();
  void testLDR();
  void controlServo(int angle);
  void writeLCD(const char *line1, const char *line2, const char *line3, const char *line4);
  void playTone(int frequency, int duration);

  // Yeni fonksiyonlar
  int analogReadPin(int pin);
  void analogWritePin(int pin, int value);
  int digitalReadPin(int pin);
  void digitalWritePin(int pin, int value);

private:
  LiquidCrystal_I2C lcd;
  Servo servo1;
  Encoder encoder;
};

#endif // IOTBOT_H
