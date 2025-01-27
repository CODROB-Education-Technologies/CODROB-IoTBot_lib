#include "IOTBOT.h"

IOTBOT::IOTBOT()
    : lcd(LCD_ADRESS, 20, 4) {}

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
  tone(BUZZER_PIN, 750, 125); // 80 Hz'de 125 ms çal
  noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 750, 100); // 90 Hz'de 100 ms çal
  noTone(BUZZER_PIN);

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

  tone(BUZZER_PIN, 800, 200); // 80 Hz'de 125 ms çal
  noTone(BUZZER_PIN);
  delay(150);
  tone(BUZZER_PIN, 1000, 100); // 90 Hz'de 100 ms çal
  noTone(BUZZER_PIN);
  delay(200);
  tone(BUZZER_PIN, 1500, 400); // 80 Hz'de 350 ms çal
  noTone(BUZZER_PIN);
}

/*********************************** Serial Port ***********************************
 */

void IOTBOT::serialStart(int baundrate)
{
  Serial.begin(baundrate);
}

void IOTBOT::serialWrite(const char *message)
{
  Serial.println(message);
}

void IOTBOT::serialWrite(int value)
{
  Serial.println(String(value).c_str());
}

void IOTBOT::serialWrite(float value)
{
  Serial.println(String(value).c_str());
}

void IOTBOT::serialWrite(bool value)
{
  Serial.println(value ? "true" : "false");
}

/*********************************** BUZZER ***********************************
 */

void IOTBOT::buzzerPlayTone(int frequency, int duration)
{
  tone(BUZZER_PIN, frequency, duration);
  delay(duration);
  noTone(BUZZER_PIN);
}

void IOTBOT::buzzerSoundIntro()
{
  tone(BUZZER_PIN, 750, 125);
  noTone(BUZZER_PIN);
  delay(150);
  tone(BUZZER_PIN, 1000, 100);
  noTone(BUZZER_PIN);
  delay(200);
  tone(BUZZER_PIN, 800, 350);
  noTone(BUZZER_PIN);
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

void IOTBOT::lcdWrite(const char *text)
{
  lcd.print(text);
}

void IOTBOT::lcdWrite(int value)
{
  lcd.print(String(value));
}

void IOTBOT::lcdWrite(float value)
{
  lcd.print(String(value));
}

void IOTBOT::lcdWrite(bool value)
{
  lcd.print(value ? "true" : "false");
}

void IOTBOT::lcdWriteCR(int col, int row, const char *text)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
  {
    return;
  }
  lcd.setCursor(col, row);
  lcd.print(text);
}

void IOTBOT::lcdWriteCR(int col, int row, int value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
  {
    return;
  }
  lcd.setCursor(col, row);
  lcd.print(String(value));
}

void IOTBOT::lcdWriteCR(int col, int row, float value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
  {
    return;
  }
  lcd.setCursor(col, row);
  lcd.print(String(value));
}

void IOTBOT::lcdWriteCR(int col, int row, bool value)
{
  if (row < 0 || row >= 4 || col < 0 || col >= 20)
  {
    return;
  }
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
void IOTBOT::relaySet(bool status)
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

int IOTBOT::joystickButtonRead()
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

int IOTBOT::button1Read()
{
  int value = analogRead(B1_AND_B2_BUTTON_PIN);

  if (value > 3500)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int IOTBOT::button2Read()
{
  int value = analogRead(B1_AND_B2_BUTTON_PIN);

  if (value > 1500 && value < 3000)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int IOTBOT::button3Read()
{
  int value = digitalRead(B3_BUTTON_PIN);

  if (value == LOW)
  {
    return 1;
  }
  else
  {
    return 0;
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

int IOTBOT::encoderButtonRead()
{
  int value = digitalRead(ENCODER_BUTTON_PIN);

  if (value)
  {
    return 1;
  }
  else
  {
    return 0;
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
void IOTBOT::moduleStepMotorMotion(bool rotation, int accelometer, int speed)
{
}

void IOTBOT::moduleDCMotorGOClockWise(int speed)
{
}

void IOTBOT::moduleDCMotorGOCounterClockWise(int speed)
{
}
void IOTBOT::moduleDCMotorStop()
{
}

void IOTBOT::moduleDCMotorBrake(int speed)
{
}

/*********************************** Servo Motor Sensor ***********************************
 */
void IOTBOT::moduleServoGoAngle(int pin, int angle, int acceleration)
{
  servoModul.write(angle);
}

/*********************************** DHT Sensor ***********************************
 */
int IOTBOT::moduleDhtTempRead(int pin)
{
}

int IOTBOT::moduleDhtHumRead(int pin)
{
}

int IOTBOT::moduleDthFeelingTemp(int pin)
{
}

/*********************************** NTC Temp Sensor ***********************************
 */
float IOTBOT::moduleNtcTempRead(int pin)
{
}

/*********************************** Magnetic Sensor ***********************************
 */
int IOTBOT::moduleMagneticRead(int pin)
{
}

/*********************************** Matris Button Sensor ***********************************
 */
int IOTBOT::moduleMatrisButtonRead(int pin)
{
}

/*********************************** Vibration Sensor ***********************************
 */
int IOTBOT::moduleVibrationRead(int pin)
{
}

/*********************************** Ultrasonic Distance Sensor ***********************************
 */
int IOTBOT::moduleUltrasonicDistanceRead()
{
}

/*********************************** Trafic Ligh Sensor ***********************************
 */
int IOTBOT::moduleTraficLightRead()
{
}

/*********************************** Smart LED Sensor ***********************************
 */
int IOTBOT::moduleSmartLEDRead(int pin)
{
}

/*********************************** Motion Sensor ***********************************
 */

int IOTBOT::moduleMotionRead(int pin)
{
}

/*********************************** Smoke Sensor ***********************************
 */
int IOTBOT::moduleSmokeRead(int pin)
{
}

/*********************************** Mic Sensor ***********************************
 */
int IOTBOT::moduleMicRead(int pin)
{
}

/*********************************** Soil Moisture Sensor ***********************************
 */
int IOTBOT::moduleSoilMoistureRead(int pin)
{
}

/*********************************** IR Sensor ***********************************
 */
int IOTBOT::moduleIRRead(int pin)
{
}

/*********************************** Relay Sensor ***********************************
 */
void IOTBOT::moduleRelayWrite(int pin)
{
}

/***********************************  Sensor ***********************************
 */
int IOTBOT::module Read()
{
}

/*********************************** OTHER PINS ***********************************
 */
int IOTBOT::analogReadPin(int pin)
{
  return analogRead(pin);
}

void IOTBOT::analogWritePin(int pin, int value)
{
  int pwmChannel = pin % 16;
  ledcAttachPin(pin, pwmChannel);
  ledcWrite(pwmChannel, value);
}

int IOTBOT::digitalReadPin(int pin)
{
  return digitalRead(pin);
}

void IOTBOT::digitalWritePin(int pin, int value)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, value);
}