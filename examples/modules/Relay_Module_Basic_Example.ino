#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Rölenin bağlı olduğu pini seçin / Select the pin connected to the relay
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Röle Testi Başlatıldı / Relay Test Started.");
    // Röle testinin başladığını seri porta yazdır / Print relay test start message to the serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Role Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    // 1️⃣ **Röleyi Aç / Activate the Relay**
    iotbot.moduleRelayWrite(SENSOR_PIN, true);
    // Röleyi aktif hale getir / Turn on the relay

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Açık / ON", "");
    // LCD'ye rölenin açık olduğunu yazdır / Display "Relay ON" status on LCD

    iotbot.serialWrite("🔌 Röle Açıldı! / 🔌 Relay Activated!");
    // Seri porta rölenin açık olduğunu yazdır / Print "Relay ON" status to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 2️⃣ **Röleyi Kapat / Deactivate the Relay**
    iotbot.moduleRelayWrite(SENSOR_PIN, false);
    // Röleyi pasif hale getir / Turn off the relay

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Kapalı / OFF", "");
    // LCD'ye rölenin kapalı olduğunu yazdır / Display "Relay OFF" status on LCD

    iotbot.serialWrite("⚡ Röle Kapandı! / ⚡ Relay Deactivated!");
    // Seri porta rölenin kapalı olduğunu yazdır / Print "Relay OFF" status to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}
