#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Duman sensörünün bağlı olduğu pini seçin / Select the pin connected to the smoke sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Duman Sensoru", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("Duman Sensörü Testi Başladı / Smoke Sensor Test Started.");
    // Seri porta test başladığını yazdır / Print test start message to serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int smokeLevel = iotbot.moduleSmokeRead(SENSOR_PIN);
    // Duman sensöründen veri oku / Read data from the smoke sensor

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.serialWrite("Duman Seviyesi / Smoke Level: ");
    iotbot.serialWrite(smokeLevel);
    // Seri porta duman seviyesini yazdır / Print smoke level to serial port

    if (smokeLevel > 1400) // Kritik eşik değeri kontrolü / Check critical threshold
    {
        iotbot.lcdWriteMid("Duman Algilandi!", "Smoke Detected!", "", "");
        // Duman algılandı mesajını LCD ekrana yazdır / Display "Smoke Detected!" message on LCD

        iotbot.serialWrite("⚠️ Duman Algılandı! / Smoke Detected!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Duman Yok", "No Smoke", "Seviye: ", String(smokeLevel).c_str());
        // Duman algılanmadığında LCD'de seviye göster / Display smoke level on LCD if no smoke detected

        iotbot.serialWrite("Duman Yok / No Smoke");
        // Seri porta duman olmadığını yazdır / Print "No Smoke" message to serial port
    }

    delay(1000);
    // Yeni okuma yapmadan önce 1 saniye bekle / Wait for 1 second before reading again
}
