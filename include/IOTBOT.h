#ifndef IOTBOT_H
#define IOTBOT_H

#if defined(ESP32)

#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Stepper.h>
#include <Adafruit_NeoPixel.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <MFRC522.h>
#include <SPI.h>
#include <EEPROM.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include <ArduinoJson.h>

// Pins
#define JOYSTICK_Y_PIN 34
#define JOYSTICK_X_PIN 15
#define JOYSTICK_BUTTON_PIN 35
#define ENCODER_A_PIN 16
#define ENCODER_B_PIN 17
#define ENCODER_BUTTON_PIN 13
#define B1_AND_B2_BUTTON_PIN 4
#define RELAY_PIN 14
#define BUZZER_PIN 12
#define LDR_PIN 39
#define POT_PIN 36
#define B3_BUTTON_PIN 0
#define LCD_ADRESS 0x27
#define LED_BUILTIN 1

#define IO25 25
#define IO26 26
#define IO27 27
#define IO32 32
#define IO33 33

class IOTBOT
{
public:
  IOTBOT();
  void begin();
  void playIntro();

  /*********************************** Serial Port ***********************************
   */
  void serialStart(int baundrate);
  void serialWrite(const char *message);
  void serialWrite(String message);
  void serialWrite(long value);
  void serialWrite(int value);
  void serialWrite(float value);
  void serialWrite(bool value);

  /*********************************** BUZZER ***********************************
   */
  void buzzerPlayTone(int frequency, int duration);
  void buzzerSoundIntro();
  void buzzertest();

  /*********************************** LCD SCREEN ***********************************
   */
  void lcdWriteMid(const char *line1, const char *line2, const char *line3, const char *line4);
  void lcdWrite(String text);
  void lcdWrite(int value);
  void lcdWrite(float value);
  void lcdWrite(bool value);
  void lcdWriteCR(int col, int row, const char *text);
  void lcdWriteCR(int col, int row, String text);
  void lcdWriteCR(int col, int row, int value);
  void lcdWriteCR(int col, int row, float value);
  void lcdWriteCR(int col, int row, bool value);
  void lcdWrite(const char *text);
  void lcdClear();
  void lcdtest();

  /*********************************** LDR ***********************************
   */
  int ldrRead();
  void ldrtest();

  /*********************************** RELAY ***********************************
   */
  void relayWrite(bool status);
  void relaytest();

  /*********************************** POTANTIOMETER ***********************************
   */
  int potentiometerRead();
  void potentiometertest();

  /*********************************** JOYSTICK ***********************************
   */
  int joystickXRead();
  int joystickYRead();
  bool joystickButtonRead();
  void joysticktest();

  /*********************************** BUTTONS ***********************************
   */
  bool button1Read();
  bool button2Read();
  bool button3Read();
  void buttonsAnalogtest();

  /*********************************** ENCODER ***********************************
   */
  int encoderRead();
  bool encoderButtonRead();
  void encodertest();

  /*********************************** DRIVER AND MOTORS ***********************************
   */
  void moduleStepMotorMotion(int step, bool rotation, int accelometer, int speed);
  void moduleDCMotorGOClockWise(int speed);
  void moduleDCMotorGOCounterClockWise(int speed);
  void moduleDCMotorStop();
  void moduleDCMotorBrake();

  /*********************************** Servo Motor Sensor ***********************************
   */
  void moduleServoGoAngle(int pin, int angle, int acceleration);

  /*********************************** DHT Sensor ***********************************
   */
  int moduleDhtTempReadC(int pin);
  int moduleDthFeelingTempC(int pin);
  int moduleDhtTempReadF(int pin);
  int moduleDthFeelingTempF(int pin);
  int moduleDhtHumRead(int pin);

  /*********************************** NTC Temp Sensor ***********************************
   */
  float moduleNtcTempRead(int pin);

  /*********************************** Magnetic Sensor ***********************************
   */
  bool moduleMagneticRead(int pin);

  /*********************************** Matris Button Sensor ***********************************
   */
  int moduleMatrisButtonAnalogRead(int pin);
  int moduleMatrisButtonNumberRead(int pin);

  /*********************************** Vibration Sensor ***********************************
   */
  bool moduleVibrationDigitalRead(int pin);
  int moduleVibrationAnalogRead(int pin);

  /*********************************** Ultrasonic Distance Sensor ***********************************
   */
  int moduleUltrasonicDistanceRead();

  /*********************************** Trafic Ligh Sensor ***********************************
   */
  void moduleTraficLightWrite(bool red, bool yellow, bool green);

  /*********************************** Smart LED Sensor ***********************************
   */
  void extendSmartLEDPrepare(int pin, int numLEDs);
  void extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue);
  void moduleSmartLEDPrepare(int pin);                             // Initialize NeoPixel strip
  void moduleSmartLEDWrite(int led, int red, int green, int blue); // Write RGB values to specific LED
  void moduleSmartLEDRainbowEffect(int wait);                      // Rainbow effect
  void moduleSmartLEDRainbowTheaterChaseEffect(int wait);          // Rainbow theater chase effect
  void moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait); // Theater chase effect
  void moduleSmartLEDColorWipeEffect(uint32_t color, int wait);    // Color wipe effect
  uint32_t getColor(int red, int green, int blue);                 // Helper function for creating colors

  /*********************************** Motion Sensor ***********************************
   */
  bool moduleMotionRead(int pin);

  /*********************************** Smoke Sensor ***********************************
   */
  int moduleSmokeRead(int pin);

  /*********************************** Mic Sensor ***********************************
   */
  int moduleMicRead(int pin);

  /*********************************** Soil Moisture Sensor ***********************************
   */
  int moduleSoilMoistureRead(int pin);

  /*********************************** IR Sensor ***********************************
   */
  String moduleIRReadHex(int pin);
  int moduleIRReadDecimalx32(int pin);
  int moduleIRReadDecimalx8(int pin);

  /*********************************** Relay Sensor ***********************************
   */
  void moduleRelayWrite(int pin, bool status);

  /*********************************** RFID Sensor ***********************************
   */
  int moduleRFIDRead(); // RFID kart ID oku / Read RFID card ID

  /*********************************** OTHER PINS ***********************************
   */
  int analogReadPin(int pin);
  void analogWritePin(int pin, int value);
  bool digitalReadPin(int pin);
  void digitalWritePin(int pin, bool value);

  /*********************************** EEPROM  ***********************************
   */
  void eepromWriteInt(int address, int value);
  int eepromReadInt(int address);

  /*********************************** WiFi  ***********************************
   */
  void wifiStartAndConnect(const char *ssid, const char *pass);
  bool wifiConnectionControl();
  String wifiGetMACAddress();
  String wifiGetIPAddress();

  /*********************************** Server  ***********************************
   */
  void serverStart(const char *mode, const char *ssid, const char *password);
  void serverCreateLocalPage(const char *url, const char *WEBPageScript, const char *WEBPageCSS, const char *WEBPageHTML);
  void serverHandleDNS();
  void serverContinue();

  /*********************************** Firebase Server  ***********************************
   */
  // 📡 Firebase Server Functions
  void fbServerSetandStart(String projectURL, String secretKey);   // projectURL: YOUR_FIREBASE_PROJECT_ID.firebaseio.com / secretKey: YOUR_FIREBASE_DATABASE_SECRET
  bool fbServerUserVerification(String userMail, String mailPass); // userMail: User mail / mailPass: mail password

  // 🔄 Firebase Database Write Functions
  void fbServerSetInt(const char *dataPath, int data);
  void fbServerSetFloat(const char *dataPath, float data);
  void fbServerSetString(const char *dataPath, String data);
  void fbServerSetDouble(const char *dataPath, double data);
  void fbServerSetBool(const char *dataPath, bool data);
  void fbServerSetJSON(const char *dataPath, String data);

  // 📥 Firebase Database Read Functions
  int fbServerGetInt(const char *dataPath);
  float fbServerGetFloat(const char *dataPath);
  String fbServerGetString(const char *dataPath);
  double fbServerGetDouble(const char *dataPath);
  bool fbServerGetBool(const char *dataPath);
  String fbServerGetJSON(const char *dataPath);

private:
  LiquidCrystal_I2C lcd;

  Servo servoModule; // Create a Servo object for controlling the servo motor
  int currentAngle = 0;

  int encoderCount; // Stores the encoder's position
  int lastStateA;   // Stores the last state of A pin
  int lastStateB;   // Stores the last state of B pin
  int counterBuzzer, counterLCD, counterLDR, counterRelay, counterPot, counterJoystick, counterButtons, counterEncoder = 0;

  void initializeDht(int pin, uint8_t type);
  DHT *dhtSensor; // Pointer to DHT sensor object

  Adafruit_NeoPixel *pixels; // NeoPixel object pointer

  void initializeIR(int pin);
  IRrecv *irrecv = nullptr; // Pointer to IR receiver / IR alıcısı için pointer
  decode_results results;   // Stores received IR results / Alınan IR sinyallerini saklar
  int irPin;                // Store the IR receiver pin / IR alıcı pini sakla
  long irRawValue = 0;      // Stores last received IR value / En son alınan IR değerini saklar

  void beginRFID();             // RFID başlat / Initialize RFID module
  MFRC522 rfid{5, 10};          // RFID modülü nesnesi / RFID module object (SS_PIN: 5, RST_PIN: 10)
  bool rfidInitialized = false; // RFID'nin başlatılıp başlatılmadığını kontrol eden bayrak / Flag to check initialization

  const IPAddress apIP = IPAddress(192, 168, 4, 1);                                // Sabit IP adresi tanımlanıyor / Define static IP address
  DNSServer dnsServer;                                                             // DNS sunucusu tanımlanıyor / Define DNS Server
  AsyncWebServer serverCODROB = AsyncWebServer(80);                                // Async Web Server nesnesi oluşturuluyor / Create an Async Web Server object
  AsyncWebSocket serverCODROBWebSocket = AsyncWebSocket("/serverCODROBWebSocket"); // WebSocket nesnesi tanımlanıyor / Define WebSocket object

  FirebaseData firebaseData;     // Data object to handle Firebase communication
  FirebaseAuth firebaseAuth;     // Authentication credentials for user verification
  FirebaseConfig firebaseConfig; // Configuration settings for Firebase
  char uid[128] = "";            // User ID storage
};

#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

#endif // IOTBOT_H
