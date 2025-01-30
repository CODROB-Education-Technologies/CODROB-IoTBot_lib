/*
 * This code is designed for the CODROB Smart LED Module.
 * Created to demonstrate the use of NeoPixel LED effects with CODROB IoTBOT.
 *
 * CODROB Akıllı LED Modülü için tasarlanmıştır.
 * Bu kod, NeoPixel LED efektlerini kullanmayı göstermek amacıyla oluşturulmuştur.
 */

#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Akıllı LED'in bağlı olduğu pini seçin / Select the pin connected to the Smart LED
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication

    iotbot.serialWrite("Akilli LED Testi Baslatildi / Smart LED Test Started.");
    // Seri porta testin başladığını yazdır / Print test start message to the serial port

    // **NeoPixel LED şeridini başlat / Initialize the NeoPixel LED strip**
    iotbot.moduleSmartLEDPrepare(SENSOR_PIN);

    iotbot.serialWrite("LED Renkleri Ayarlaniyor / Setting Initial LED Colors...");

    // **Başlangıç renklerini ayarla / Set initial LED colors**
    delay(1000);
    iotbot.moduleSmartLEDWrite(0, 255, 0, 0); // **LED 0: Kırmızı / Red**
    iotbot.serialWrite("LED 0 - Kirmizi (Red) Yakildi.");
    delay(1000);

    iotbot.moduleSmartLEDWrite(1, 0, 255, 0); // **LED 1: Yeşil / Green**
    iotbot.serialWrite("LED 1 - Yesil (Green) Yakildi.");
    delay(1000);

    iotbot.moduleSmartLEDWrite(2, 0, 0, 255); // **LED 2: Mavi / Blue**
    iotbot.serialWrite("LED 2 - Mavi (Blue) Yakildi.");
    delay(1000);
}

void loop()
{
    // 1️⃣ **Gökkuşağı Efekti / Rainbow Effect**
    iotbot.serialWrite("🎨 Gokkusagi Efekti Calisiyor / Running Rainbow Effect...");
    iotbot.moduleSmartLEDRainbowEffect(50);
    // Yumuşak geçişli gökkuşağı efekti uygula / Apply smooth rainbow effect
    delay(1000);

    // 2️⃣ **Gökkuşağı Tiyatro Takip Efekti / Rainbow Theater Chase Effect**
    iotbot.serialWrite("🌈 Gokkusagi Tiyatro Takip Efekti Calisiyor / Running Rainbow Theater Chase Effect...");
    iotbot.moduleSmartLEDRainbowTheaterChaseEffect(50);
    // Gökkuşağı renklerinde tiyatro ışık takip efekti / Rainbow theater chase effect
    delay(1000);

    // 3️⃣ **Kırmızı Tiyatro Takip Efekti / Red Theater Chase Effect**
    iotbot.serialWrite("🎭 Kirmizi Tiyatro Efekti Calisiyor / Running Red Theater Chase Effect...");
    iotbot.moduleSmartLEDTheaterChaseEffect(iotbot.getColor(255, 0, 0), 50);
    // Kırmızı tiyatro ışık takip efekti uygula / Apply red theater chase effect
    delay(1000);

    // 4️⃣ **Mavi Renk Temizleme Efekti / Blue Color Wipe Effect**
    iotbot.serialWrite("💙 Mavi Renk Temizleme Efekti Calisiyor / Running Blue Color Wipe Effect...");
    iotbot.moduleSmartLEDColorWipeEffect(iotbot.getColor(0, 0, 255), 50);
    // Mavi renk temizleme efekti uygula / Apply blue color wipe effect
    delay(1000);
}
