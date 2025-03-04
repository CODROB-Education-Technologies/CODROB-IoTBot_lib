#include <IOTBOT_Config.h>
#include "IOTBOT.h"

/*********************************** Constructor ***********************************/

IOTBOT::IOTBOT() : lcd(LCD_ADRESS, 20, 4)
{
#if defined(USE_SERVER)
  serverCODROBWebSocket = new AsyncWebSocket("/serverCODROBWebSocket");
#endif
}

/*********************************** BEGIN ***********************************/
void IOTBOT::begin()
{
  pinMode(JOYSTICK_Y_PIN, INPUT);
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);
  pinMode(ENCODER_BUTTON_PIN, INPUT_PULLUP);
  pinMode(B1_AND_B2_BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(POT_PIN, INPUT);
  pinMode(B3_BUTTON_PIN, INPUT_PULLUP);

  // Reset encoder count and read initial states
  encoderCount = 0;
  lastStateA = digitalRead(ENCODER_A_PIN);
  lastStateB = digitalRead(ENCODER_B_PIN);

  // LCD begin
  lcd.init();
  lcd.backlight();
  lcd.clear();

  analogWrite(BUZZER_PIN, 750);
  delay(125);
  analogWrite(BUZZER_PIN, 0);
  delay(100);
  analogWrite(BUZZER_PIN, 700);
  delay(100);
  analogWrite(BUZZER_PIN, 0);

  lcd.setCursor(3, 1);
  lcd.print("--- IoTBot ---");
  lcd.setCursor(4, 3);
  lcd.print("from  CODROB");
}

void IOTBOT::playIntro()
{
  lcd.clear();
  delay(50);

  lcd.setCursor(3, 1);
  lcd.print("Hi There!");
  delay(200);
  lcd.setCursor(10, 2);
  lcd.print("Merhaba!");
  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Bonjour!");
  delay(200);
  lcd.setCursor(1, 3);
  lcd.print("Hallo!");
  delay(200);
  lcd.setCursor(12, 0);
  lcd.print("Hola!");
  delay(200);
  lcd.setCursor(14, 1);
  lcd.print("Ciao!");
  delay(200);
  lcd.setCursor(2, 2);
  lcd.print("Ola!");
  delay(200);
  lcd.setCursor(9, 3);
  lcd.print("Konnichiwa!");
  delay(1000);

  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("--- IoTBot ---");
  lcd.setCursor(4, 3);
  lcd.print("from  CODROB");
  delay(500);

  analogWrite(BUZZER_PIN, 800);
  delay(200);
  analogWrite(BUZZER_PIN, 0);
  delay(150);
  analogWrite(BUZZER_PIN, 1000);
  delay(100);
  analogWrite(BUZZER_PIN, 0);
  delay(200);
  analogWrite(BUZZER_PIN, 1500);
  delay(400);
  analogWrite(BUZZER_PIN, 0);
}

/*********************************** Serial Port ***********************************
 */
void IOTBOT::serialStart(int baudrate)
{
  Serial.begin(baudrate);
}

void IOTBOT::serialWrite(const char *message) // Overloaded function for const char* / `const char*` için fonksiyon
{
  Serial.println(message);
}

void IOTBOT::serialWrite(String message) // Overloaded function for String / `String` için özel fonksiyon
{
  Serial.println(message.c_str()); // Convert String to const char*
}

void IOTBOT::serialWrite(long value) // Overloaded function for long / `long` için özel fonksiyon
{
  Serial.println(String(value).c_str());
}

void IOTBOT::serialWrite(int value) // Overloaded function for int / `int` için fonksiyon
{
  Serial.println(String(value).c_str());
}

void IOTBOT::serialWrite(float value) // Overloaded function for float / `float` için fonksiyon
{
  Serial.println(String(value).c_str());
}

void IOTBOT::serialWrite(bool value) // Overloaded function for bool / `bool` için fonksiyon
{
  Serial.println(value ? "true" : "false");
}

/*********************************** BUZZER ***********************************
 */
void IOTBOT::buzzerPlayTone(int frequency, int duration)
{
  analogWrite(BUZZER_PIN, frequency);
  delay(duration);
  analogWrite(BUZZER_PIN, 0);
}

void IOTBOT::buzzerSoundIntro()
{
  analogWrite(BUZZER_PIN, 750);
  delay(125);
  analogWrite(BUZZER_PIN, 0);
  delay(150);
  analogWrite(BUZZER_PIN, 1000);
  delay(100);
  analogWrite(BUZZER_PIN, 0);
  delay(200);
  analogWrite(BUZZER_PIN, 800);
  delay(400);
  analogWrite(BUZZER_PIN, 0);
}

void IOTBOT::buzzertest()
{
  if (counterBuzzer < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(5, 1);
    lcd.print("Buzzer Test");

    counterBuzzer++;
  }
  lcd.setCursor(6, 3);
  lcd.print("Beeping!");
  buzzerPlayTone(1000, 500);
  lcd.setCursor(6, 3);
  lcd.print(" Silent.");
  delay(500);
}

/*********************************** LCD SCREEN ***********************************
 */
void IOTBOT::lcdWriteMid(const char *line1, const char *line2, const char *line3, const char *line4)
{
  lcd.clear();

  // Define the number of columns in the LCD (e.g., 20 for a 20x4 LCD display)
  const int lcdColumns = 20;

  // Calculate the length of each line
  int len1 = strlen(line1);
  int len2 = strlen(line2);
  int len3 = strlen(line3);
  int len4 = strlen(line4);

  // Calculate the starting column for each line to center-align the text
  int startCol1 = (lcdColumns - len1) / 2;
  int startCol2 = (lcdColumns - len2) / 2;
  int startCol3 = (lcdColumns - len3) / 2;
  int startCol4 = (lcdColumns - len4) / 2;

  // Ensure the starting column is not negative (in case the text is too long)
  startCol1 = max(0, startCol1);
  startCol2 = max(0, startCol2);
  startCol3 = max(0, startCol3);
  startCol4 = max(0, startCol4);

  // Print each line on the LCD at the calculated starting column
  lcd.setCursor(startCol1, 0); // Line 0
  lcd.print(line1);

  lcd.setCursor(startCol2, 1); // Line 1
  lcd.print(line2);

  lcd.setCursor(startCol3, 2); // Line 2
  lcd.print(line3);

  lcd.setCursor(startCol4, 3); // Line 3
  lcd.print(line4);
}

void IOTBOT::lcdWrite(const char *text) // Overloaded function for const char* / `const char*` için fonksiyon
{
  lcd.print(text);
}

void IOTBOT::lcdWrite(String text) // Overloaded function for String / `String` için özel fonksiyon
{
  lcd.print(text.c_str()); // Convert String to const char*
}

void IOTBOT::lcdWrite(int value)
{
  lcd.print(String(value));
}

void IOTBOT::lcdWrite(float value) // Overloaded function for float / `float` için fonksiyon
{
  lcd.print(String(value));
}

void IOTBOT::lcdWrite(bool value) // Overloaded function for bool / `bool` için fonksiyon
{
  lcd.print(value ? "true" : "false");
}

void IOTBOT::lcdSetCursor(int col, int row)
{
  lcd.setCursor(col, row);
}

void IOTBOT::lcdWriteCR(int col, int row, const char *text)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
    return;
  lcd.setCursor(col, row);
  lcd.print(text);
}

void IOTBOT::lcdWriteCR(int col, int row, String text)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
    return;
  lcd.setCursor(col, row);
  lcd.print(text.c_str()); // Convert String to const char*
}

void IOTBOT::lcdWriteCR(int col, int row, int value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
    return;
  lcd.setCursor(col, row);
  lcd.print(String(value));
}

void IOTBOT::lcdWriteCR(int col, int row, float value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
    return;
  lcd.setCursor(col, row);
  lcd.print(String(value));
}

void IOTBOT::lcdWriteCR(int col, int row, bool value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
    return;
  lcd.setCursor(col, row);
  lcd.print(value ? "true" : "false");
}

void IOTBOT::lcdClear()
{
  lcd.clear();
}

void IOTBOT::lcdtest()
{
  if (counterLCD < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(7, 1);
    lcd.print("LCD Test");

    counterLCD++;
  }

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Hi, my name is");
  lcd.setCursor(3, 1);
  lcd.print("--- IoTBot ---");
  lcd.setCursor(4, 3);
  lcd.print("from  CODROB");
  delay(5000);
}

/*********************************** LDR ***********************************
 */
int IOTBOT::ldrRead()
{
  return analogRead(LDR_PIN);
}

void IOTBOT::ldrtest()
{
  if (counterLDR < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(6, 1);
    lcd.print("LDR Test");
    lcd.setCursor(5, 3);
    lcd.print("Value: ");
    counterLDR++;
  }
  int value = analogRead(LDR_PIN);
  lcd.setCursor(12, 3);
  lcd.print(value);
  lcd.print("   ");
}

/*********************************** RELAY ***********************************
 */
void IOTBOT::relayWrite(bool status)
{
  digitalWrite(RELAY_PIN, status);
}

void IOTBOT::relaytest()
{
  if (counterRelay < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(5, 1);
    lcd.print("Relay Test");

    counterRelay++;
  }
  lcd.setCursor(6, 3);
  lcd.print(" Open!");
  digitalWrite(RELAY_PIN, HIGH);
  delay(500);
  lcd.setCursor(6, 3);
  lcd.print("Close!");
  digitalWrite(RELAY_PIN, LOW);
  delay(500);
}

/*********************************** POTANTIOMETER ***********************************
 */
int IOTBOT::potentiometerRead()
{
  return analogRead(POT_PIN);
}

void IOTBOT::potentiometertest()
{
  if (counterPot < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(1, 1);
    lcd.print("Potantiometer Test");
    lcd.setCursor(4, 3);
    lcd.print("Value: ");

    counterPot++;
  }
  int value = analogRead(POT_PIN);
  lcd.setCursor(11, 3);
  lcd.print(value);
  lcd.print("   ");
}

/*********************************** JOYSTICK ***********************************
 */
int IOTBOT::joystickXRead()
{
  return analogRead(JOYSTICK_X_PIN);
}

int IOTBOT::joystickYRead()
{
  return analogRead(JOYSTICK_Y_PIN);
}

bool IOTBOT::joystickButtonRead()
{
  return digitalRead(JOYSTICK_BUTTON_PIN);
}

void IOTBOT::joysticktest()
{
  if (counterJoystick < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(3, 1);
    lcd.print("Joystick Test");
    lcd.setCursor(0, 2);
    lcd.print("X: ");
    lcd.setCursor(10, 2);
    lcd.print("Y: ");

    lcd.setCursor(2, 3);
    lcd.print("Button Status: ");

    counterJoystick++;
  }

  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  int buttonStatus = digitalRead(JOYSTICK_BUTTON_PIN);

  lcd.setCursor(3, 2);
  lcd.print(xValue);
  lcd.print("   ");
  lcd.setCursor(13, 2);
  lcd.print(yValue);
  lcd.print("   ");
  lcd.setCursor(17, 3);
  lcd.print(buttonStatus);
}

/*********************************** BUTTONS ***********************************
 */
bool IOTBOT::button1Read()
{
  int value = analogRead(B1_AND_B2_BUTTON_PIN);

  if (value > 3500)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool IOTBOT::button2Read()
{
  int value = analogRead(B1_AND_B2_BUTTON_PIN);

  if (value > 1500 && value < 3000)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool IOTBOT::button3Read()
{
  int value = digitalRead(B3_BUTTON_PIN);

  if (value == LOW)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void IOTBOT::buttonsAnalogtest()
{
  if (counterButtons < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(0, 1);
    lcd.print("Analog Button Test");
    lcd.setCursor(1, 2);
    lcd.print("Button value : ");

    lcd.setCursor(1, 3);
    counterButtons++;
  }

  int buttonValue = analogRead(B1_AND_B2_BUTTON_PIN);
  int B3value = digitalRead(B3_BUTTON_PIN);

  lcd.setCursor(16, 2);
  lcd.print(buttonValue);

  if (buttonValue > 3500)
  {
    lcd.setCursor(6, 3);
    lcd.print("B1");
  }
  else if (buttonValue > 1500 && buttonValue < 3000)
  {
    lcd.setCursor(6, 3);
    lcd.print("B2");
  }
  else
  {
    lcd.setCursor(17, 2);
    lcd.print("   ");
    lcd.setCursor(6, 3);
    lcd.print("  ");
  }

  if (B3value == LOW)
  {
    lcd.setCursor(14, 3);
    lcd.print("B3");
  }
  else
  {
    lcd.setCursor(14, 3);
    lcd.print("  ");
  }
}

/*********************************** ENCODER ***********************************
 */
int IOTBOT::encoderRead()
{
  // Read current states of A and B pins
  int currentStateA = digitalRead(ENCODER_A_PIN);
  int currentStateB = digitalRead(ENCODER_B_PIN);

  // Check if A pin state has changed
  if (currentStateA != lastStateA)
  {
    if (currentStateA == HIGH)
    {
      // Determine direction based on B pin state
      if (currentStateB == LOW)
      {
        encoderCount--; // Counterclockwise
      }
      else
      {
        encoderCount++; // Clockwise
      }
    }
  }

  // Update last states
  lastStateA = currentStateA;
  lastStateB = currentStateB;

  // Return the current encoder count
  return encoderCount;
}

bool IOTBOT::encoderButtonRead()
{
  int value = digitalRead(ENCODER_BUTTON_PIN);

  if (value)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void IOTBOT::encodertest()
{
  if (counterEncoder < 1)
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("-IotBot-");
    lcd.setCursor(4, 1);
    lcd.print("Encoder Test");
    lcd.setCursor(1, 2);
    lcd.print("Encoder value : ");

    lcd.setCursor(1, 3);
    lcd.print("Encoder button: ");
    counterEncoder++;
  }

  int buttonStatus = digitalRead(ENCODER_BUTTON_PIN);
  int currentStateA = digitalRead(ENCODER_A_PIN);
  int currentStateB = digitalRead(ENCODER_B_PIN);

  // Check if A pin state has changed
  if (currentStateA != lastStateA)
  {
    if (currentStateA == HIGH)
    {
      // Determine direction based on B pin state
      if (currentStateB == LOW)
      {
        encoderCount--; // Counterclockwise
      }
      else
      {
        encoderCount++; // Clockwise
      }
    }
  }

  // Update last states
  lastStateA = currentStateA;
  lastStateB = currentStateB;

  lcd.setCursor(17, 2);
  lcd.print(encoderCount);
  lcd.print("   ");
  lcd.setCursor(17, 3);
  lcd.print(buttonStatus);
}

/*********************************** DRIVER AND MOTORS ***********************************
 */
/*********************************** Stepper Motor Motion ***********************************
 * Controls the stepper motor.
 * rotation: True for clockwise, false for counterclockwise.
 * accelometer: Number of steps to move.
 * speed: Speed of the stepper motor in RPM.
 */
void IOTBOT::moduleStepMotorMotion(int step, bool rotation, int accelometer, int speed)
{
  // Stepper motor object (shared across the library)
  Stepper stepMotor(step, IO26, IO33, IO32, IO27); // 50 steps per revolution, pins 26, 33, 32, 27

  stepMotor.setSpeed(speed); // Set the speed of the stepper motor

  if (rotation)
  {
    stepMotor.step(accelometer); // Move forward (clockwise)
  }
  else
  {
    stepMotor.step(-accelometer); // Move backward (counterclockwise)
  }
}

/*********************************** DC Motor Clockwise ***********************************
 * Rotates the DC motor clockwise at the specified speed.
 * speed: Motor speed (0 to 255 for PWM).
 */
void IOTBOT::moduleDCMotorGOClockWise(int speed)
{
  pinMode(IO26, OUTPUT); // Direction control pin
  pinMode(IO27, OUTPUT); // PWM control pin

  // Map speed from 0-100 to 0-255 for PWM
  int pwmValue = map(speed, 0, 100, 0, 255);

  digitalWrite(IO26, LOW);     // Set direction to clockwise
  analogWrite(IO27, pwmValue); // Set motor speed using PWM
}

/*********************************** DC Motor Counter-Clockwise ***********************************
 * Rotates the DC motor counterclockwise at the specified speed.
 * speed: Motor speed (0 to 255 for PWM).
 */
void IOTBOT::moduleDCMotorGOCounterClockWise(int speed)
{
  pinMode(IO26, OUTPUT); // Direction control pin
  pinMode(IO27, OUTPUT); // PWM control pin

  // Map speed from 0-100 to 0-255 for PWM
  int pwmValue = map(speed, 0, 100, 0, 255);

  digitalWrite(IO26, pwmValue); // Set direction to counterclockwise
  analogWrite(IO27, LOW);       // Set motor speed using PWM
}

/*********************************** DC Motor Stop ***********************************
 * Stops the DC motor by setting PWM to 0.
 */
void IOTBOT::moduleDCMotorStop()
{
  pinMode(IO26, OUTPUT);
  pinMode(IO27, OUTPUT);

  digitalWrite(IO26, LOW);
  digitalWrite(IO27, LOW);
}

/*********************************** DC Motor Brake ***********************************
 * Brakes the DC motor using a hardware brake.
 */
void IOTBOT::moduleDCMotorBrake()
{
  pinMode(IO26, OUTPUT);
  pinMode(IO27, OUTPUT);

  digitalWrite(IO26, HIGH);
  digitalWrite(IO27, HIGH);
}

/*********************************** NTC Temp Sensor ***********************************
 * Reads the NTC temperature sensor value and calculates the temperature in Celsius.
 * pin: The analog pin where the NTC is connected.
 */
float IOTBOT::moduleNtcTempRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);

  // NTC constants
  const float R_NOMINAL = 10000.0;       // Nominal resistance at 25°C (10k ohms)
  const float T_NOMINAL = 25.0;          // Nominal temperature (25°C)
  const float B_COEFFICIENT = 3950.0;    // Beta coefficient of the thermistor
  const float SERIES_RESISTOR = 10000.0; // Resistor value in series with the NTC

  // Read the analog value from the pin
  int analogValue = analogRead(pin);

  // Convert the analog value to resistance
  float resistance = SERIES_RESISTOR / ((4095.0 / analogValue) - 1.0);

  // Calculate the temperature using the Steinhart-Hart equation
  float steinhart = resistance / R_NOMINAL; // (R / R_NOMINAL)
  steinhart = log(steinhart);               // ln(R/R_NOMINAL)
  steinhart /= B_COEFFICIENT;               // 1/B * ln(R/R_NOMINAL)
  steinhart += 1.0 / (T_NOMINAL + 273.15);  // + (1/T_NOMINAL)
  steinhart = 1.0 / steinhart;              // Invert
  steinhart -= 273.15;                      // Convert Kelvin to Celsius

  return steinhart;
}

/*********************************** Magnetic Sensor ***********************************
 */
bool IOTBOT::moduleMagneticRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return !digitalRead(pin);
}

/*********************************** Matris Button Sensor ***********************************
 */
int IOTBOT::moduleMatrisButtonAnalogRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

int IOTBOT::moduleMatrisButtonNumberRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  int value = analogRead(pin);
  if (value > 4000)
  {
    return 1;
  }
  else if (value > 2350 && value < 2500)
  {
    return 2;
  }
  else if (value > 2210 && value < 2350)
  {
    return 3;
  }
  else if (value > 2150 && value < 2210)
  {
    return 4;
  }
  else if (value > 2000 && value < 2150)
  {
    return 5;
  }
  else
  {
    return 0;
  }
}

/*********************************** Vibration Sensor ***********************************
 */
bool IOTBOT::moduleVibrationDigitalRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

int IOTBOT::moduleVibrationAnalogRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

/*********************************** Ultrasonic Distance Sensor ***********************************
 * Reads distance from the ultrasonic sensor using echo and trigger pins.
 * Automatically adjusts for ESP32 and ESP8266 platforms.
 * Returns 0 if the distance exceeds the maximum measurable range (400 cm).
 */
int IOTBOT::moduleUltrasonicDistanceRead()
{
#if defined(ESP32)
  const int TRIG_PIN = IO27;
  const int ECHO_PIN = IO32;
#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

  // Maximum measurable distance for HC-SR04 (in centimeters)
  const int MAX_DISTANCE = 400;

  // Configure pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Send a 10-microsecond pulse on the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(ECHO_PIN, HIGH, MAX_DISTANCE * 58); // Timeout for MAX_DISTANCE

  // If no echo is received, return 0 (out of range)
  if (duration == 0)
  {
    return 0; // Out of range or no object detected
  }

  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2; // Sound speed: 0.034 cm/µs, divide by 2 for round trip

  // If the calculated distance exceeds the maximum range, return 0
  if (distance > MAX_DISTANCE)
  {
    return 000;
  }

  return distance; // Return the measured distance
}

/*********************************** Trafic Ligh Sensor ***********************************
 */
void IOTBOT::moduleTraficLightWrite(bool red, bool yellow, bool green)
{
#if defined(ESP32)
  const int RED_PIN = IO32;
  const int YELLOW_PIN = IO26;
  const int GREEN_PIN = IO25;
#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

  // Configure pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  if (red)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, LOW);
  }
  if (yellow)
  {
    digitalWrite(YELLOW_PIN, HIGH);
  }
  else
  {
    digitalWrite(YELLOW_PIN, LOW);
  }
  if (green)
  {
    digitalWrite(GREEN_PIN, HIGH);
  }
  else
  {
    digitalWrite(GREEN_PIN, LOW);
  }
}

void IOTBOT::moduleTraficLightWriteRed(bool red)
{
#if defined(ESP32)
  const int RED_PIN = IO32;
#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

  // Configure pins
  pinMode(RED_PIN, OUTPUT);

  if (red)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, LOW);
  }
}
void IOTBOT::moduleTraficLightWriteYellow(bool yellow)
{
#if defined(ESP32)
  const int YELLOW_PIN = IO26;
#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

  // Configure pins
  pinMode(YELLOW_PIN, OUTPUT);

  if (yellow)
  {
    digitalWrite(YELLOW_PIN, HIGH);
  }
  else
  {
    digitalWrite(YELLOW_PIN, LOW);
  }
}

void IOTBOT::moduleTraficLightWriteGreen(bool green)
{
#if defined(ESP32)
  const int GREEN_PIN = IO25;
#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

  // Configure pins
  pinMode(GREEN_PIN, OUTPUT);

  if (green)
  {
    digitalWrite(GREEN_PIN, HIGH);
  }
  else
  {
    digitalWrite(GREEN_PIN, LOW);
  }
}

/*********************************** Motion Sensor ***********************************
 */
bool IOTBOT::moduleMotionRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

/*********************************** Smoke Sensor ***********************************
 */
int IOTBOT::moduleSmokeRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

/*********************************** Mic Sensor ***********************************
 */
int IOTBOT::moduleMicRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

/*********************************** Soil Moisture Sensor ***********************************
 */
int IOTBOT::moduleSoilMoistureRead(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

/*********************************** Relay Sensor ***********************************
 */
void IOTBOT::moduleRelayWrite(int pin, bool status)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, status);
}

/*********************************** OTHER PINS ***********************************
 */
int IOTBOT::analogReadPin(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return analogRead(pin);
}

void IOTBOT::analogWritePin(int pin, int value)
{
  pinMode(pin, OUTPUT);
  // int pwmChannel = pin % 16;
  // ledcAttachPin(pin, pwmChannel);
  // ledcWrite(pwmChannel, value);
  analogWrite(pin, value); // ESP8266 için normal PWM
}

bool IOTBOT::digitalReadPin(int pin)
{
  // Configure pins
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

void IOTBOT::digitalWritePin(int pin, bool value)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, value);
}

/*********************************** EEPROM  ***********************************
 */
void IOTBOT::eepromWriteInt(int address, int value) // EEPROM'a güvenli bir şekilde int türünde veri yazmak için fonksiyon
{
  byte highByte = highByte(value); // int'in yüksek baytını al
  byte lowByte = lowByte(value);   // int'in düşük baytını al

  EEPROM.write(address, highByte);    // İlk baytı EEPROM'a yaz
  EEPROM.write(address + 1, lowByte); // İkinci baytı EEPROM'a yaz
  EEPROM.commit();                    // Değişiklikleri kaydetmek için commit işlemi yapılmalıdır
}

int IOTBOT::eepromReadInt(int address) // EEPROM'dan int türünde veri okumak için fonksiyon
{
  byte highByte = EEPROM.read(address);    // İlk baytı oku
  byte lowByte = EEPROM.read(address + 1); // İkinci baytı oku
  return word(highByte, lowByte);          // Yüksek ve düşük baytları birleştirerek int değeri oluştur
}

/*********************************** Servo Angle Control ***********************************
 * Moves a servo to the specified angle with optional acceleration control.
 * pin: The GPIO pin connected to the servo signal.
 * angle: The target angle for the servo (0° to 180°).
 * acceleration: The delay (in milliseconds) between incremental movements.
 */
#ifdef USE_SERVO // Eğer main.cpp içinde tanımlandıysa, burada aktif olur

void IOTBOT::moduleServoGoAngle(int pin, int angle, int acceleration)
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
#endif

/*********************************** DHT Sensor Initialization ***********************************
 * Configures the DHT sensor.
 * This is automatically initialized when reading temperature or humidity.
 */
#if defined(USE_DHT)

void IOTBOT::initializeDht(int pin, uint8_t type)
{
  if (!dhtSensor)
  {
    dhtSensor = new DHT(pin, type); // Create a new DHT object
    dhtSensor->begin();             // Initialize the sensor
  }
}

int IOTBOT::moduleDhtTempReadC(int pin) // Read Temperature
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized
  float temp = dhtSensor->readTemperature();

  if (isnan(temp)) // Check if reading failed
    return -999;

  return static_cast<int>(temp);
}

int IOTBOT::moduleDthFeelingTempC(int pin) // Calculate Heat Index (Feeling Temperature)
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized

  float temp = dhtSensor->readTemperature();
  float hum = dhtSensor->readHumidity();

  if (isnan(temp) || isnan(hum)) // Check if readings failed
    return -999;

  float heatIndex = dhtSensor->computeHeatIndex(temp, hum, false); // Calculate heat index in Celsius
  return static_cast<int>(heatIndex);
}

int IOTBOT::moduleDhtTempReadF(int pin) // Read Temperature in Fahrenheit
{
  initializeDht(pin, DHT11);                     // Ensure DHT11 is initialized
  float temp = dhtSensor->readTemperature(true); // **Fahrenheit sıcaklık okuma**

  if (isnan(temp)) // Check if reading failed
    return -999;

  return static_cast<int>(temp);
}

int IOTBOT::moduleDthFeelingTempF(int pin) // Calculate Heat Index (Feeling Temperature in Fahrenheit)
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized

  float temp = dhtSensor->readTemperature(true); // **Fahrenheit sıcaklık okuma**
  float hum = dhtSensor->readHumidity();         // **Nem okuma**

  if (isnan(temp) || isnan(hum)) // Check if readings failed
    return -999;

  float heatIndex = dhtSensor->computeHeatIndex(temp, hum, true); // **Fahrenheit olarak hissedilen sıcaklık hesapla**
  return static_cast<int>(heatIndex);
}

int IOTBOT::moduleDhtHumRead(int pin) // Read Humidity
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized
  float hum = dhtSensor->readHumidity();

  if (isnan(hum)) // Check if reading failed
    return -999;

  return static_cast<int>(hum);
}
#endif

/*********************************** Smart LED Sensor ***********************************
 */
#if defined(USE_NEOPIXEL)
void IOTBOT::extendSmartLEDPrepare(int pin, int numLEDs)
{
  // Create a new Adafruit_NeoPixel object dynamically
  pixels = new Adafruit_NeoPixel(numLEDs, pin, NEO_GRB + NEO_KHZ800);
  pixels->begin(); // Initialize the NeoPixel strip
  pixels->show();  // Turn off all LEDs initially
}

void IOTBOT::extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue)
{
  if (pixels)
  {
    // Set the color for a range of LEDs
    for (int i = startLED; i <= endLED; i++)
    {
      pixels->setPixelColor(i, pixels->Color(red, green, blue));
    }
    pixels->show(); // Update the LEDs
  }
}

void IOTBOT::moduleSmartLEDPrepare(int pin)
{
  pixels = new Adafruit_NeoPixel(3, pin, NEO_GRB + NEO_KHZ800);
  pixels->begin();
  pixels->show(); // Clear all LEDs
}

void IOTBOT::moduleSmartLEDWrite(int led, int red, int green, int blue)
{
  if (pixels)
  {
    pixels->setPixelColor(led, pixels->Color(red, green, blue));
    pixels->show();
  }
}

uint32_t IOTBOT::getColor(int red, int green, int blue)
{
  return pixels->Color(red, green, blue);
}

void IOTBOT::moduleSmartLEDRainbowEffect(int wait)
{
  if (pixels)
  {
    for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256)
    {
      for (int i = 0; i < pixels->numPixels(); i++)
      {
        int pixelHue = firstPixelHue + (i * 65536L / pixels->numPixels());
        pixels->setPixelColor(i, pixels->gamma32(pixels->ColorHSV(pixelHue)));
      }
      pixels->show();
      delay(wait);
    }
  }
}

void IOTBOT::moduleSmartLEDRainbowTheaterChaseEffect(int wait)
{
  if (pixels)
  {
    int firstPixelHue = 0;
    for (int a = 0; a < 30; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        pixels->clear();
        for (int c = b; c < pixels->numPixels(); c += 3)
        {
          int hue = firstPixelHue + c * 65536L / pixels->numPixels();
          uint32_t color = pixels->gamma32(pixels->ColorHSV(hue));
          pixels->setPixelColor(c, color);
        }
        pixels->show();
        delay(wait);
        firstPixelHue += 65536 / 90;
      }
    }
  }
}

void IOTBOT::moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait)
{
  if (pixels)
  {
    for (int a = 0; a < 10; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        pixels->clear();
        for (int c = b; c < pixels->numPixels(); c += 3)
        {
          pixels->setPixelColor(c, color);
        }
        pixels->show();
        delay(wait);
      }
    }
  }
}

void IOTBOT::moduleSmartLEDColorWipeEffect(uint32_t color, int wait)
{
  if (pixels)
  {
    for (int i = 0; i < pixels->numPixels(); i++)
    {
      pixels->setPixelColor(i, color);
      pixels->show();
      delay(wait);
    }
  }
}
#endif

/*********************************** RFID Sensor ***********************************
 */
#if defined(USE_RFID)

void IOTBOT::beginRFID()
{
  SPI.begin();            // SPI başlat
  rfid.PCD_Init();        // RFID başlat
  rfidInitialized = true; // RFID'nin başlatıldığını işaretle / Mark RFID as initialized
}

int IOTBOT::moduleRFIDRead()
{
  // Eğer RFID başlatılmadıysa, otomatik başlat / If RFID is not initialized, initialize it
  if (!rfidInitialized)
  {
    beginRFID();
  }

  String rfidNum = "";

  if (!rfid.PICC_IsNewCardPresent())
    return 0;
  if (!rfid.PICC_ReadCardSerial())
    return 0;

  for (byte i = 0; i < 4; i++)
  {
    rfidNum += String(rfid.uid.uidByte[i]);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  return rfidNum.toInt();
}
#endif

/*********************************** IR Sensor ***********************************
 */
#if defined(USE_IR)

void IOTBOT::initializeIR(int pin) // Initialize the IR module / IR modülünü başlat
{
  if (!irrecv || irPin != pin)
  {                                           // Eğer IR alıcı yoksa veya pin değişmişse baştan başlat
    irPin = pin;                              // Store the IR receiver pin / IR alıcı pini sakla
    delete irrecv;                            // Önceki nesneyi temizle
    irrecv = new IRrecv(pin, 1024, 50, true); // Create a new IRrecv instance / Yeni bir IRrecv nesnesi oluştur
    irrecv->enableIRIn();                     // Start the IR receiver / IR alıcıyı başlat
  }
}

String IOTBOT::moduleIRReadHex(int pin) // Read IR signal in hexadecimal format / IR sinyalini HEX formatında oku
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    String hexCode = "0x" + String(results.value, HEX); // Convert to HEX / HEX formatına çevir
    irrecv->resume();                                   // Continue receiving new data / Yeni veri almak için devam et
    return hexCode;
  }
  return "0"; // No signal received / Sinyal yoksa 0 döndür
}

int IOTBOT::moduleIRReadDecimalx32(int pin) // Read IR signal as a full 32-bit decimal value / IR sinyalini tam 32-bit ondalık formatta oku
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    int decimalCode = results.value; // Return the full 32-bit value / Tam 32-bit değeri döndür
    irrecv->resume();                // Continue receiving new data / Yeni veri almak için devam et
    return decimalCode;
  }
  return 0; // No signal received / Sinyal yoksa 0 döndür
}

int IOTBOT::moduleIRReadDecimalx8(int pin) // Read IR signal as only the last 8 bits (for smaller values) / IR sinyalini sadece son 8 bit olarak oku (küçük değerler için)
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    int smallCode = results.value & 0xFF; // Extract only the last 8 bits / Sadece son 8 biti al
    irrecv->resume();                     // Continue receiving new data / Yeni veri almak için devam et
    return smallCode;
  }
  return 0; // No signal received / Sinyal yoksa 0 döndür
}
#endif

/*********************************** WiFi ***********************************/
#if defined(USE_WIFI)
void IOTBOT::wifiStartAndConnect(const char *ssid, const char *pass)
{
  Serial.printf("[WiFi]: Connection Starting!\r\n[WiFi]: SSID: %s\r\n[WiFi]: Pass: %s\r\n", ssid, pass);

  WiFi.begin(ssid, pass);
  int count = 0;
  while (count < 30)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.printf("\n[WiFi]: Connected!\r\n[WiFi]: Local IP: %s\r\n", WiFi.localIP().toString().c_str());
      Serial.printf("[WiFi]: MAC Address: %s\r\n", WiFi.macAddress().c_str());
      return;
    }
    Serial.print(".");
    delay(500);
    count++;
  }
  Serial.println();
  Serial.println("[WiFi]: Connection Timeout!");
}

bool IOTBOT::wifiConnectionControl()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("[WiFi]: Connection OK!");
    return true;
  }
  else
  {
    Serial.println("[WiFi]: Connection ERROR!");
    return false;
  }
}

String IOTBOT::wifiGetMACAddress()
{
  return WiFi.macAddress();
}

String IOTBOT::wifiGetIPAddress()
{
  return WiFi.localIP().toString();
}
#endif

/*********************************** Server ***********************************/
#if defined(USE_SERVER)

void IOTBOT::serverStart(const char *mode, const char *ssid, const char *password)
{
  if (strcmp(mode, "STA") == 0)
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.printf("\n[STA Mode]: Connecting to WiFi: %s\n", ssid);

    int retries = 30;
    while (WiFi.status() != WL_CONNECTED && retries > 0)
    {
      delay(1000);
      Serial.print(".");
      retries--;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("\n[STA Mode]: Connected!");
      Serial.printf("[STA Mode]: IP Address: http://%s\n", WiFi.localIP().toString().c_str());
    }
    else
    {
      Serial.println("\n[STA Mode]: Connection Failed! Switching to AP Mode...");
      serverStart("AP", ssid, password);
      return;
    }
  }
  else if (strcmp(mode, "AP") == 0)
  {
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0));
    dnsServer.start(53, "*", IPAddress(192, 168, 4, 1));

    Serial.printf("\n[AP Mode]: Access Point Started!\n");
    Serial.printf("[AP Mode]: SSID: \"%s\"\n", ssid);
    Serial.printf("[AP Mode]: Password: \"%s\"\n", password);
    Serial.printf("[AP Mode]: AP IP Address: http://%s\n", WiFi.softAPIP().toString().c_str());
  }

  // 📌 Sayfaları tanımla
  serverCODROB.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                  {
      Serial.println("[Local Server]: Root URL Accessed!");
      request->send(200, "text/plain", "CODROB Server is Running!"); });

  // 📌 404 Hatası
  serverCODROB.onNotFound([](AsyncWebServerRequest *request)
                          {
      Serial.println("[Local Server]: Received an Unknown Request!");
      request->send(404, "text/plain", "Not Found"); });

  // 📌 **WebSocket Olaylarını Bağla**
  serverCODROBWebSocket->onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
                                 {
      if (type == WS_EVT_CONNECT) {
          Serial.println("WebSocket Client Connected");
      } else if (type == WS_EVT_DISCONNECT) {
          Serial.println("WebSocket Client Disconnected");
      } });

  // 📌 WebSocket'i Sunucuya Bağla
  serverCODROB.addHandler(serverCODROBWebSocket);

  // 📌 **En son sunucuyu başlat!**
  serverCODROB.begin();
  Serial.println("[Local Server]: Server Started! ✅");
}

void IOTBOT::serverCreateLocalPage(const char *url, const char *WEBPageScript, const char *WEBPageCSS, const char *WEBPageHTML, size_t bufferSize)
{
  // 📌 Sayfa içeriğini oluştur
  serverCODROB.on(("/" + String(url)).c_str(), HTTP_GET, [WEBPageScript, WEBPageCSS, WEBPageHTML, bufferSize](AsyncWebServerRequest *request)
                  {
                    // Buffer boyutu kullanıcının belirttiği veya varsayılan değerle tanımlanır
                    char *buffer = new char[bufferSize];
                    int len = snprintf(buffer, bufferSize, WEBPageHTML, WEBPageScript, WEBPageCSS);

                    if (len >= bufferSize)
                    {
                      Serial.println("[ERROR]: Buffer size insufficient, content truncated!");
                    }

                    request->send(200, "text/html", buffer);
                    delete[] buffer; // Dinamik olarak ayrılan belleği serbest bırakın
                  });

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.printf("[Local Server]: Page created at: http://%s/%s\n", WiFi.localIP().toString().c_str(), url);
  }
  else
  {
    Serial.printf("[Local Server]: Page created at: http://%s/%s\n", apIP.toString().c_str(), url);
  }
}

void IOTBOT::serverHandleDNS()
{
  dnsServer.processNextRequest();
}

void IOTBOT::serverContinue()
{
  if (WiFi.getMode() == WIFI_AP)
  {
    serverHandleDNS();
  }
}
#endif

/*********************************** Firebase Server Functions ***********************************/
#if defined(USE_FIREBASE)

// Initialize Firebase connection with SignUp Authentication
void IOTBOT::fbServerSetandStartWithUser(const char *projectURL, const char *secretKey, const char *userMail, const char *mailPass)
{
  firebaseData.setResponseSize(1024); // Optimize memory usage

  // Firebase Configuration Settings
  firebaseConfig.api_key = secretKey;
  firebaseConfig.database_url = projectURL;
  firebaseAuth.user.email = userMail;
  firebaseAuth.user.password = mailPass;

  // Zaman aşımı ayarları
  firebaseConfig.timeout.socketConnection = 10 * 1000; // 10 saniye bağlantı zaman aşımı

  // Token durumu izleme ayarı
  // firebaseConfig.token_status_callback = tokenStatusCallback;
  firebaseConfig.max_token_generation_retry = 5; // Daha fazla token yenileme denemesi

  // Wi-Fi bağlantısı kaybolduğunda otomatik yeniden bağlanma
  Firebase.reconnectWiFi(true);

  // Firebase başlat
  Serial.println("[Firebase]: Firebase connection starting...");
  Firebase.begin(&firebaseConfig, &firebaseAuth);

  Serial.println("[Firebase]: Verifying user credentials...");
  uint8_t id_count = 0;
  while (firebaseAuth.token.uid == "" && id_count < 50)
  {
    Serial.print('.');
    delay(500);
    id_count++;
  }
  if (firebaseAuth.token.uid == "")
  {
    Serial.println("\n[ERROR]: Authentication timeout.");
  }
  else
  {
    if (Firebase.ready())
    {
      strncpy(uid, firebaseAuth.token.uid.c_str(), 128 - 1); // UID'yi kopyala ve taşma kontrolü yap
      uid[128 - 1] = '\0';                                   // Diziyi null karakter ile sonlandır
      Serial.print("\n[Info]: Doğrulanan Kimlik ID: ");
      Serial.println(uid);
    }
    else
    {
      Serial.print("[ERROR]: Sign-up failed. Reason: ");
      Serial.println(firebaseData.errorReason());
    }
  }
}

/*********************************** Firebase Write Functions ***********************************/

void IOTBOT::fbServerSetInt(const char *dataPath, int data)
{
  // Corrected function call
  if (Firebase.RTDB.setInt(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Integer data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send integer data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void IOTBOT::fbServerSetFloat(const char *dataPath, float data)
{
  if (Firebase.RTDB.setFloat(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Float data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send float data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void IOTBOT::fbServerSetString(const char *dataPath, String data)
{
  if (Firebase.RTDB.setString(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: String data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send string data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void IOTBOT::fbServerSetDouble(const char *dataPath, double data)
{
  if (Firebase.RTDB.setDouble(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Double data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send double data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void IOTBOT::fbServerSetBool(const char *dataPath, bool data)
{
  if (Firebase.RTDB.setBool(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Boolean data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send boolean data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void IOTBOT::fbServerSetJSON(const char *dataPath, String data)
{
  FirebaseJson json;
  json.set(dataPath, data);

  if (Firebase.RTDB.setJSON(&firebaseData, dataPath, &json))
  {
    Serial.println("[SUCCESS]: JSON data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send JSON data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

/*********************************** Firebase Read Functions ***********************************/

int IOTBOT::fbServerGetInt(const char *dataPath)
{
  if (Firebase.RTDB.getInt(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Integer data retrieved successfully!");
    return firebaseData.intData();
  }
  Serial.println("[ERROR]: Failed to retrieve integer data.");
  return -1;
}

float IOTBOT::fbServerGetFloat(const char *dataPath)
{
  if (Firebase.RTDB.getFloat(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Float data retrieved successfully!");
    return firebaseData.floatData();
  }
  Serial.println("[ERROR]: Failed to retrieve float data.");
  return -1.0;
}

String IOTBOT::fbServerGetString(const char *dataPath)
{
  if (Firebase.RTDB.getString(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: String data retrieved successfully!");
    return firebaseData.stringData();
  }
  Serial.println("[ERROR]: Failed to retrieve string data.");
  return "";
}

double IOTBOT::fbServerGetDouble(const char *dataPath)
{
  if (Firebase.RTDB.getDouble(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Double data retrieved successfully!");
    return firebaseData.doubleData();
  }
  Serial.println("[ERROR]: Failed to retrieve double data.");
  return -1.0;
}

bool IOTBOT::fbServerGetBool(const char *dataPath)
{
  if (Firebase.RTDB.getBool(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Boolean data retrieved successfully!");
    return firebaseData.boolData();
  }
  Serial.println("[ERROR]: Failed to retrieve boolean data.");
  return false;
}

String IOTBOT::fbServerGetJSON(const char *dataPath)
{
  if (Firebase.RTDB.getJSON(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: JSON data retrieved successfully!");
    return firebaseData.jsonString();
  }
  Serial.println("[ERROR]: Failed to retrieve JSON data.");
  return "{}";
}
#endif

/*********************************** xxxxxxxxxxxxxxxxxxx ***********************************/
