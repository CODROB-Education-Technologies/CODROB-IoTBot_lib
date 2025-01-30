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

    iotbot.lcdWriteMid("Trafik Isigi", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("Trafik Işığı Testi Başladı / Traffic Light Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    // 1️⃣ **Kırmızı Işık / Red Light**
    iotbot.moduleTraficLightWrite(true, false, false);
    // Kırmızı ışığı yak, diğerlerini söndür / Turn on red light, turn off others

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Kirmizi Isik", "Red Light", "", "");
    // LCD'ye kırmızı ışık bilgisini yazdır / Display "Red Light" status on LCD

    iotbot.serialWrite("🚦 Kırmızı Işık Yandı / Red Light ON");
    // Seri porta kırmızı ışığın yandığını yazdır / Print "Red Light ON" message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 2️⃣ **Sarı Işık / Yellow Light**
    iotbot.moduleTraficLightWrite(false, true, false);
    // Sarı ışığı yak, diğerlerini söndür / Turn on yellow light, turn off others

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Sari Isik", "Yellow Light", "", "");
    // LCD'ye sarı ışık bilgisini yazdır / Display "Yellow Light" status on LCD

    iotbot.serialWrite("🚦 Sarı Işık Yandı / Yellow Light ON");
    // Seri porta sarı ışığın yandığını yazdır / Print "Yellow Light ON" message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds

    // 3️⃣ **Yeşil Işık / Green Light**
    iotbot.moduleTraficLightWrite(false, false, true);
    // Yeşil ışığı yak, diğerlerini söndür / Turn on green light, turn off others

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Yesil Isik", "Green Light", "", "");
    // LCD'ye yeşil ışık bilgisini yazdır / Display "Green Light" status on LCD

    iotbot.serialWrite("🚦 Yeşil Işık Yandı / Green Light ON");
    // Seri porta yeşil ışığın yandığını yazdır / Print "Green Light ON" message to serial port

    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}
