#define USE_NEOPIXEL

#include <IOTBOT.h> // IoTBot kutuphanesi / IoTBot library

// IoTBot nesnesi olusturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Akilli LED'in bagli oldugu pini secin / Select the pin connected to the Smart LED
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot baslatiliyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri haberlesmeyi baslat / Start serial communication

    iotbot.serialWrite("Akilli LED Testi Baslatildi / Smart LED Test Started.");
    // Seri porta testin basladigini yazdir / Print test start message to the serial port

    // **NeoPixel LED seridini baslat / Initialize the NeoPixel LED strip**
    iotbot.moduleSmartLEDPrepare(SENSOR_PIN);

    iotbot.serialWrite("LED Renkleri Ayarlaniyor / Setting Initial LED Colors...");

    // **Baslangic renklerini ayarla / Set initial LED colors**
    delay(1000);
    iotbot.moduleSmartLEDWrite(0, 255, 0, 0); // **LED 0: Kirmizi / Red**
    iotbot.serialWrite("LED 0 - Kirmizi (Red) Yakildi.");
    delay(1000);

    iotbot.moduleSmartLEDWrite(1, 0, 255, 0); // **LED 1: Yesil / Green**
    iotbot.serialWrite("LED 1 - Yesil (Green) Yakildi.");
    delay(1000);

    iotbot.moduleSmartLEDWrite(2, 0, 0, 255); // **LED 2: Mavi / Blue**
    iotbot.serialWrite("LED 2 - Mavi (Blue) Yakildi.");
    delay(1000);
}

void loop()
{
    // 1️⃣ **Gokkusagi Efekti / Rainbow Effect**
    iotbot.serialWrite("🎨 Gokkusagi Efekti Calisiyor / Running Rainbow Effect...");
    iotbot.moduleSmartLEDRainbowEffect(50);
    // Yumusak gecisli gokkusagi efekti uygula / Apply smooth rainbow effect
    delay(1000);

    // 2️⃣ **Gokkusagi Tiyatro Takip Efekti / Rainbow Theater Chase Effect**
    iotbot.serialWrite("🌈 Gokkusagi Tiyatro Takip Efekti Calisiyor / Running Rainbow Theater Chase Effect...");
    iotbot.moduleSmartLEDRainbowTheaterChaseEffect(50);
    // Gokkusagi renklerinde tiyatro isik takip efekti / Rainbow theater chase effect
    delay(1000);

    // 3️⃣ **Kirmizi Tiyatro Takip Efekti / Red Theater Chase Effect**
    iotbot.serialWrite("🎭 Kirmizi Tiyatro Efekti Calisiyor / Running Red Theater Chase Effect...");
    iotbot.moduleSmartLEDTheaterChaseEffect(iotbot.getColor(255, 0, 0), 50);
    // Kirmizi tiyatro isik takip efekti uygula / Apply red theater chase effect
    delay(1000);

    // 4️⃣ **Mavi Renk Temizleme Efekti / Blue Color Wipe Effect**
    iotbot.serialWrite("💙 Mavi Renk Temizleme Efekti Calisiyor / Running Blue Color Wipe Effect...");
    iotbot.moduleSmartLEDColorWipeEffect(iotbot.getColor(0, 0, 255), 50);
    // Mavi renk temizleme efekti uygula / Apply blue color wipe effect
    delay(1000);
}
