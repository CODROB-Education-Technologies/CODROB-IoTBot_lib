#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Mikrofon sensörünün bağlı olduğu pini seçin / Select the pin connected to the microphone sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Mikrofon Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("Mikrofon Sensör Testi Başlatıldı / Microphone Sensor Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to the serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int micValue = iotbot.moduleMicRead(SENSOR_PIN);
    // Mikrofon sensöründen gelen veriyi oku / Read data from the microphone sensor

    iotbot.serialWrite("Mikrofon Sensör Değeri / Microphone Sensor Value: " + String(micValue));
    // Mikrofon sensör değerini seri porta yazdır / Print microphone sensor value to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    if (micValue > 1000) // Gürültü seviyesi eşik değer kontrolü / Noise level threshold check
    {
        iotbot.lcdWriteMid("⚠️ Yuksek Ses!", "⚠️ High Noise!", "Seviye: ", String(micValue).c_str());
        // Gürültü seviyesi yüksekse uyarı mesajı göster / Display warning message if noise level is high

        iotbot.serialWrite("⚠️ Yuksek Ses Algılandı! / ⚠️ High Noise Detected!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Mikrofon Degeri:", "Microphone Value:", String(micValue).c_str(), "");
        // Mikrofon değerini LCD ekrana yazdır / Display microphone value on LCD

        iotbot.serialWrite("Ses Seviyesi Normal / Sound Level Normal");
        // Seri porta normal ses seviyesi mesajı yazdır / Print normal sound level message to serial port
    }

    delay(500); // Yeni okuma yapmadan önce 500 ms bekle / Wait for 500 ms before reading again
}
