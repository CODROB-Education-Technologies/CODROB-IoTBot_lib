#define USE_SERVO

#include <IOTBOT.h> // IoTBot kutuphanesi / IoTBot library

// IoTBot nesnesi olusturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Servo motorun bagli oldugu pini secin / Select the pin connected to the servo motor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot baslatiliyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberlesmeyi baslat / Start serial communication
    // Bilgisayar ile seri haberlesme icin 115200 baud hizinda baslatilir.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Servo Motor Testi Baslatildi / Servo Motor Test Started.");
    // Servo motor testinin basladigini seri porta yazdir / Print servo motor test start message to the serial port

    iotbot.lcdWriteMid("--- IoTBot ---", "Servo Motor", "Test Basladi", "Test Started");
    // LCD'ye test basladigini yazdir / Display test start message on LCD

    delay(3000); // Baslangic icin bekleme suresi / Initial delay

    iotbot.lcdClear(); // LCD ekrani temizle / Clear the LCD screen

    iotbot.lcdWriteCR(5, 1, "Angle / Aci");
    // LCD'ye "Aci" basligini yazdir / Display "Angle" label on LCD
}

void loop()
{
    // 1️⃣ **Servo Motoru 0° Acisina Gotur / Move Servo Motor to 0° Position**
    iotbot.serialWrite("Angle / Aci: 0");
    // Seri porta 0° aciyi yazdir / Print 0° angle to the serial port

    iotbot.lcdWriteCR(9, 2, " 0 ");
    // LCD'ye 0° aciyi yazdir / Display 0° angle on LCD

    iotbot.moduleServoGoAngle(SENSOR_PIN, 0, 5);
    // Servo motoru 0° acisina gotur (Hareket hizi: 5 birim) / Move servo motor to 0° position (Movement speed: 5 units)

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 2️⃣ **Servo Motoru 90° Acisina Gotur / Move Servo Motor to 90° Position**
    iotbot.serialWrite("Angle / Aci: 90");
    // Seri porta 90° aciyi yazdir / Print 90° angle to the serial port

    iotbot.lcdWriteCR(9, 2, " 90 ");
    // LCD'ye 90° aciyi yazdir / Display 90° angle on LCD

    iotbot.moduleServoGoAngle(SENSOR_PIN, 90, 7);
    // Servo motoru 90° acisina gotur (Hareket hizi: 7 birim) / Move servo motor to 90° position (Movement speed: 7 units)

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 3️⃣ **Servo Motoru 180° Acisina Gotur / Move Servo Motor to 180° Position**
    iotbot.serialWrite("Angle / Aci: 180");
    // Seri porta 180° aciyi yazdir / Print 180° angle to the serial port

    iotbot.lcdWriteCR(9, 2, "180");
    // LCD'ye 180° aciyi yazdir / Display 180° angle on LCD

    iotbot.moduleServoGoAngle(SENSOR_PIN, 180, 10);
    // Servo motoru 180° acisina gotur (Hareket hizi: 10 birim) / Move servo motor to 180° position (Movement speed: 10 units)

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 4️⃣ **Servo Motoru Tekrar 0° Acisina Gotur / Move Servo Motor Back to 0°**
    iotbot.serialWrite("Angle / Aci: 0");
    // Seri porta 0° aciyi tekrar yazdir / Print 0° angle again to the serial port

    iotbot.lcdWriteCR(9, 2, " 0 ");
    // LCD'ye 0° aciyi tekrar yazdir / Display 0° angle again on LCD

    iotbot.moduleServoGoAngle(SENSOR_PIN, 0, 5);
    // Servo motoru tekrar 0° acisina gotur (Hareket hizi: 5 birim) / Move servo motor back to 0° position (Movement speed: 5 units)

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
