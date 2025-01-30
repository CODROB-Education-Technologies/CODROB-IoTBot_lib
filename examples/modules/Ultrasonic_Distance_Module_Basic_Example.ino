#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Ultrasonik sensör testi başlatıldı / Ultrasonic sensor test started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Ultrasonik Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int distance = iotbot.moduleUltrasonicDistanceRead();
    // Ultrasonik sensörden mesafeyi oku / Measure distance using the ultrasonic sensor

    iotbot.serialWrite("Mesafe / Distance: ");
    iotbot.serialWrite(distance);
    // Seri porta mesafe bilgisini yazdır / Print distance value to serial port

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    if (distance < 10) // Tehlikeli mesafe kontrolü / Check for dangerous distance
    {
        iotbot.lcdWriteMid("⚠️ Cok Yakin!", "⚠️ Too Close!", "Mesafe: ", String(distance).c_str());
        // Tehlikeli derecede yakın mesafe için uyarı göster / Display warning if too close

        iotbot.serialWrite("⚠️ Cok Yakin! / ⚠️ Too Close!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Mesafe:", "Distance:", String(distance).c_str(), " cm");
        // Mesafeyi LCD'ye yazdır / Display distance value on LCD

        iotbot.serialWrite("Guvenli Mesafe / Safe Distance");
        // Seri porta güvenli mesafe mesajı yazdır / Print safe distance message to serial port
    }

    delay(1000);
    // Yeni okuma yapmadan önce 1 saniye bekle / Wait for 1 second before reading again
}
