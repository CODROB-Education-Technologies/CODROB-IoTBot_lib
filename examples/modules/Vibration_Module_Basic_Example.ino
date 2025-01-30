#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Titreşim sensörünün bağlı olduğu pini seçin / Select the pin connected to the vibration sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Titreşim sensör testi başlatıldı / Vibration sensor test started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Titreşim Sensoru", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int vibrationStatus = iotbot.moduleVibrationAnalogRead(SENSOR_PIN);
    // Titreşim sensöründen veri oku / Read data from the vibration sensor

    iotbot.serialWrite("Titreşim Değeri / Vibration Value: ");
    iotbot.serialWrite(vibrationStatus);
    // Seri porta titreşim değerini yazdır / Print vibration value to serial port

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    if (vibrationStatus > 1000) // Yüksek titreşim kontrolü / Check for high vibration level
    {
        iotbot.lcdWriteMid("⚠️ Yuksek Titreşim!", "⚠️ High Vibration!", "Seviye: ", String(vibrationStatus).c_str());
        // Yüksek titreşim algılandığında LCD'de uyarı göster / Display warning on LCD if high vibration detected

        iotbot.serialWrite("⚠️ Yüksek Titreşim Algılandı! / ⚠️ High Vibration Detected!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Titreşim Seviyesi:", "Vibration Level:", String(vibrationStatus).c_str(), "");
        // Titreşim seviyesini LCD'ye yazdır / Display vibration level on LCD

        iotbot.serialWrite("Titreşim Normal / Normal Vibration");
        // Seri porta normal durum mesajı yazdır / Print normal vibration status to serial port
    }

    delay(500);
    // Yeni okuma yapmadan önce 500 ms bekle / Wait for 500 ms before reading again
}
