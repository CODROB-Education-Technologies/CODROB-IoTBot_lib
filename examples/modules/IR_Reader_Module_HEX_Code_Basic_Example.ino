#include <IOTBOT.h> // IOTBOT kütüphanesi / IOTBOT library

// IOTBOT nesnesi oluştur / Create an IOTBOT object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // IR sensörünün bağlı olduğu pini seçin / Select the pin connected to the IR sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IOTBOT başlatılıyor / Initialize IOTBOT

    iotbot.serialStart(115200); // Seri haberleşmeyi 115200 baud hızıyla başlat / Start serial communication at 115200 baud
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("IR Okuyucu testi başlatıldı / IR Reader test started.");
    // IR sensör testinin başladığını seri porta yazdır / Print IR sensor test start message to the serial port

    delay(2000); // Başlangıç gecikmesi (2 saniye) / Initial delay (2 seconds)

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    // **LCD ekrana başlık ve açıklamaları yazdır / Display title and description on the LCD**
    iotbot.lcdWriteMid("IotBot", "IR Reader Test", "", "HEX value:        ");
}

void loop()
{
    // **IR sensöründen gelen HEX formatındaki veriyi oku / Read HEX formatted data from IR sensor**
    String value = iotbot.moduleIRReadHex(SENSOR_PIN);

    // **Eğer geçerli bir veri alındıysa (0 değilse) ekrana ve seri porta yazdır / If valid data is received (not "0"), print to LCD and serial port**
    if (value != "0")
    {
        // **LCD ekrana HEX kodunu yaz (4. satır, 11. sütundan itibaren) / Write HEX code to LCD (Row 4, Column 11)**
        iotbot.lcdWriteCR(11, 3, value);

        // **Seri port üzerinden HEX kodunu gönder / Send HEX code via serial port**
        iotbot.serialWrite("Hex Code:");
        iotbot.serialWrite(value);
    }
    else
    {
        // **Eğer sinyal alınmazsa ekranda bekleme durumu göster / If no signal is received, show waiting status on LCD**
        iotbot.lcdWriteCR(11, 3, "Waiting...");
        iotbot.serialWrite("No IR Signal Received.");
    }

    delay(500); // 500ms bekleme süresi / 500ms delay
}
