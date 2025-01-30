#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Akıllı LED'in bağlı olduğu pini seçin / Select the pin connected to the Smart LED
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("🟢 Smart LED testi başlatıldı / Smart LED test started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen
    iotbot.lcdWriteMid("Smart LED", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(2000); // Başlangıç bekleme süresi / Initial delay

    iotbot.moduleSmartLEDPrepare(SENSOR_PIN);
    // Akıllı LED'leri başlat / Initialize Smart LED
}

void loop()
{
    // 🔴 **Kırmızı LED**
    iotbot.serialWrite("🔴 Kırmızı LED yanıyor / Red LED ON.");
    // Seri porta mesaj yazdır / Print message to serial port

    iotbot.lcdClear();
    iotbot.lcdWriteMid("Smart LED", "LED:", "Kırmızı / Red", "");
    // LCD'ye kırmızı LED bilgisini yazdır / Display red LED status on LCD

    iotbot.moduleSmartLEDWrite(0, 255, 0, 0);
    // Kırmızı LED'i yak / Turn on the red LED

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 🟢 **Yeşil LED**
    iotbot.serialWrite("🟢 Yeşil LED yanıyor / Green LED ON.");
    // Seri porta mesaj yazdır / Print message to serial port

    iotbot.lcdClear();
    iotbot.lcdWriteMid("Smart LED", "LED:", "Yeşil / Green", "");
    // LCD'ye yeşil LED bilgisini yazdır / Display green LED status on LCD

    iotbot.moduleSmartLEDWrite(1, 0, 255, 0);
    // Yeşil LED'i yak / Turn on the green LED

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 🔵 **Mavi LED**
    iotbot.serialWrite("🔵 Mavi LED yanıyor / Blue LED ON.");
    // Seri porta mesaj yazdır / Print message to serial port

    iotbot.lcdClear();
    iotbot.lcdWriteMid("Smart LED", "LED:", "Mavi / Blue", "");
    // LCD'ye mavi LED bilgisini yazdır / Display blue LED status on LCD

    iotbot.moduleSmartLEDWrite(2, 0, 0, 255);
    // Mavi LED'i yak / Turn on the blue LED

    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 🚫 **Tüm LED'leri kapat / Turn off all LEDs**
    iotbot.serialWrite("🚫 Tüm LED'ler kapatılıyor / Turning OFF all LEDs.");
    // Seri porta LED kapatma mesajı yazdır / Print LED off message to serial port

    iotbot.lcdClear();
    iotbot.lcdWriteMid("Smart LED", "LED:", "Kapalı / OFF", "");
    // LCD'ye LED'lerin kapatıldığını yazdır / Display LED off status on LCD

    iotbot.moduleSmartLEDWrite(0, 0, 0, 0);
    iotbot.moduleSmartLEDWrite(1, 0, 0, 0);
    iotbot.moduleSmartLEDWrite(2, 0, 0, 0);
    // Tüm LED'leri kapat / Turn off all LEDs

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
