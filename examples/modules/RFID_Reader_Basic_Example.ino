#include <IOTBOT.h> // 📌 IoTBot kütüphanesi

// 📌 **IoTBot nesnesi oluştur**
IOTBOT iotbot;

void setup()
{
    iotbot.begin();    // 📌 IoTBot başlatılıyor / Initialize IoTBot
    iotbot.lcdClear(); // 📌 LCD ekranı temizle / Clear LCD screen

    // 📌 **Seri port ve LCD'ye başlangıç mesajı**
    iotbot.serialWrite("RFID Okuyucu Başlatılıyor... / Starting RFID Reader...");
    iotbot.lcdWriteMid("RFID Modulu", "--- IoTBot ---", "Hazir!", "Ready!");

    delay(2000); // 2 saniye bekle / Wait 2 seconds
}

void loop()
{
    int rfidID = iotbot.moduleRFIDRead(); // 📌 RFID kartı oku / Read RFID card

    if (rfidID != 0) // 📌 **Kart okutulduysa işlem yap**
    {
        // 📌 **Seri porta RFID bilgisini yazdır**
        iotbot.serialWrite("📌 Okunan RFID ID: " + String(rfidID));

        // 📌 **LCD ekranda RFID bilgisini göster**
        iotbot.lcdClear();
        iotbot.lcdWriteMid("RFID Kart Okundu!", "RFID Scanned!", "ID:", String(rfidID).c_str());

        delay(2000); // 2 saniye bekle / Wait 2 seconds
    }
}
