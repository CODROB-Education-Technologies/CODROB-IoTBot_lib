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

    // **LCD'ye başlık ve açıklamaları yazdır / Display title and description on the LCD**
    iotbot.lcdWriteMid("IotBot", "IR Reader Test", "", "Decimal value:        ");
}

void loop()
{
    // **IR sensöründen gelen ondalık (decimal) veriyi oku / Read decimal data from IR sensor**
    long value = iotbot.moduleIRReadDecimalx32(SENSOR_PIN);
    // Alternatif olarak 8-bit formatında değer almak için aşağıdaki satırı kullanabilirsiniz:
    // Alternatively, use the following line to get an 8-bit formatted value:
    // long value = iotbot.moduleIRReadDecimalx8(SENSOR_PIN);

    // **Eğer geçerli bir veri alındıysa (0 değilse) ekrana ve seri porta yazdır / If valid data is received (not "0"), print to LCD and serial port**
    if (value != 0)
    {
        // **LCD ekrana decimal kodunu yaz (4. satır, 11. sütundan itibaren) / Write decimal code to LCD (Row 4, Column 11)**
        iotbot.lcdWriteCR(11, 3, String(value).c_str());

        // **Seri port üzerinden decimal kodunu gönder / Send decimal code via serial port**
        iotbot.serialWrite("Decimal Code:");
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
