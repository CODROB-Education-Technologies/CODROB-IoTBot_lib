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

    iotbot.lcdWriteMid("DC Motor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("DC Motor Testi Başladı / DC Motor Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    // 1️⃣ **Saat Yönünde Hareket / Clockwise Motion**
    iotbot.moduleDCMotorGOClockWise(50);
    // Motoru saat yönünde %50 hızda döndür / Rotate motor clockwise at 50% speed

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("DC Motor", "Direction:", "Clockwise", "Speed: 50%");
    // LCD'ye yön ve hız bilgilerini yazdır / Display direction and speed on LCD

    iotbot.serialWrite("🔄 DC Motor Saat Yönünde Döndü / DC Motor Rotating Clockwise at 50% Speed");
    // Seri porta saat yönünde döndüğünü yazdır / Print clockwise rotation message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 2️⃣ **Saat Yönünün Tersine Hareket / Counterclockwise Motion**
    iotbot.moduleDCMotorGOCounterClockWise(75);
    // Motoru saat yönünün tersine %75 hızda döndür / Rotate motor counterclockwise at 75% speed

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("DC Motor", "Direction:", "CounterClockwise", "Speed: 75%");
    // LCD'ye yön ve hız bilgilerini yazdır / Display direction and speed on LCD

    iotbot.serialWrite("🔄 DC Motor Saat Yönünün Tersine Döndü / DC Motor Rotating Counterclockwise at 75% Speed");
    // Seri porta saat yönünün tersine döndüğünü yazdır / Print counterclockwise rotation message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 3️⃣ **Motoru Durdur / Stop the Motor**
    iotbot.moduleDCMotorStop();
    // Motoru durdur / Stop the motor

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("DC Motor", "Motor Stopped", "", "");
    // LCD'ye motorun durduğunu yazdır / Display motor stop message on LCD

    iotbot.serialWrite("🛑 DC Motor Durduruldu / DC Motor Stopped");
    // Seri porta motorun durduğunu yazdır / Print motor stop message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}
