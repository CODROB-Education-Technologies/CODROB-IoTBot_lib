#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    iotbot.serialWrite("📺 LCD testi başlatıldı / LCD test started.");

    // LCD giriş mesajı / LCD startup message
    iotbot.lcdClear();
    iotbot.lcdWriteMid("LCD Test", "--- IoTBot ---", "Test Başladı!", "Starting Test!");
    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}

void loop()
{
    // 📌 **Temel LCD Mesajları / Basic LCD Messages**
    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "IoTBot LCD Test");
    iotbot.lcdWriteCR(0, 1, "Satır 1 / Row 1");
    iotbot.lcdWriteCR(0, 2, "Satır 2 / Row 2");
    iotbot.lcdWriteCR(0, 3, "Satır 3 / Row 3");
    iotbot.serialWrite("🖥 LCD temel metinler yazıldı.");
    delay(2000);

    // 📌 **LCD'de Hareketli Yazı Testi / Scrolling Text Test**
    iotbot.lcdClear();
    iotbot.serialWrite("📜 Hareketli metin başlatıldı...");
    for (int i = 0; i < 16; i++) // 16 sütun kaydırma yap
    {
        iotbot.lcdWriteCR(i, 1, "-> IoTBot <-"); // Yazıyı sağa kaydır / Shift text to the right
        delay(150);                              // 150 ms bekle / Wait for 150 ms
        iotbot.lcdClear();
    }

    // 📌 **Sayı Sayacı Testi / Number Counter Test**
    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "Sayı Test / Numbers:");
    for (int i = 0; i <= 10; i++)
    {
        iotbot.lcdWriteCR(12, 1, String(i)); // Sayıları yazdır / Print numbers
        iotbot.serialWrite("🔢 Sayı: " + String(i));
        delay(500);
    }

    // 📌 **Başarı Mesajı / Success Message**
    iotbot.lcdClear();
    iotbot.lcdWriteMid("IoTBot Testi", "LCD Modulu", "BAŞARILI!", "SUCCESSFUL!");
    iotbot.serialWrite("✅ LCD testi başarıyla tamamlandı.");
    delay(5000);
}
