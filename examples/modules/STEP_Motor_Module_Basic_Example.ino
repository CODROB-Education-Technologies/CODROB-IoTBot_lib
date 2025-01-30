#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Stepper Motor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("Stepper Motor Testi Başladı / Stepper Motor Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    // 1️⃣ **Saat Yönünde Hareket / Clockwise Motion**
    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Stepper Motor", "Direction:", "Clockwise", "Steps: 100");
    // LCD'ye saat yönünde hareket bilgisi yazdır / Display clockwise motion info on LCD

    iotbot.serialWrite("Stepper Motor Saat Yönünde Hareket Ediyor / Stepper Motor Moving Clockwise");
    // Saat yönünde hareket mesajını seri porta yazdır / Print clockwise motion message to serial port

    iotbot.moduleStepMotorMotion(50, true, 100, 60);
    // Step motoru 100 adım saat yönünde döndür, hız 60 RPM / Rotate stepper motor 100 steps clockwise at 60 RPM

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 2️⃣ **Saat Yönünün Tersine Hareket / Counterclockwise Motion**
    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Stepper Motor", "Direction:", "CounterClockwise", "Steps: 100");
    // LCD'ye saat yönünün tersi hareket bilgisi yazdır / Display counterclockwise motion info on LCD

    iotbot.serialWrite("Stepper Motor Saat Yönünün Tersine Hareket Ediyor / Stepper Motor Moving Counterclockwise");
    // Saat yönünün tersine hareket mesajını seri porta yazdır / Print counterclockwise motion message to serial port

    iotbot.moduleStepMotorMotion(50, false, 100, 60);
    // Step motoru 100 adım saat yönünün tersine döndür, hız 60 RPM / Rotate stepper motor 100 steps counterclockwise at 60 RPM

    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}
