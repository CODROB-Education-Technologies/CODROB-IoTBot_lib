#include <IOTBOT.h> // IOTBOT kütüphanesi / IOTBOT library

// IOTBOT nesnesi oluştur / Create an IOTBOT object
IOTBOT iotbot;

void setup()
{
    iotbot.begin();             // IOTBOT başlat / Initialize IOTBOT
    iotbot.serialStart(115200); // Seri haberleşmeyi 115200 baud hızıyla başlat / Start serial communication at 115200 baud
    iotbot.serialWrite("IR Okuyucu testi başlatıldı / IR Reader test started.");

    delay(2000); // Başlangıç gecikmesi (2 saniye) / Initial delay (2 seconds)

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    // LCD ekrana başlık ve açıklamaları yazdır
    iotbot.lcdWriteMid("IotBot", "IR Reader Test", "", "HEX value:        ");
}

void loop()
{
    // IR sensöründen gelen HEX verisini oku / Read HEX data from IR sensor
    String value = iotbot.moduleIRReadHex(IO27);

    // Eğer geçerli bir veri alındıysa (sıfır değilse) / If valid data is received (not "0")
    if (value != "0")
    {
        // LCD ekrana HEX kodunu yaz (4. satır, 11. sütundan itibaren) / Write HEX code to LCD (Row 4, Column 11)
        iotbot.lcdWriteCR(11, 3, value);

        // Seri port üzerinden HEX kodunu gönder / Send HEX code via serial port
        iotbot.serialWrite("Hex Code:");
        iotbot.serialWrite(value);
    }
}