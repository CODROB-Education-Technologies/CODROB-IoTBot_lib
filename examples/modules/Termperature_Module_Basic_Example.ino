#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // NTC sıcaklık sensörünün bağlı olduğu pini seçin / Select the pin connected to the NTC temperature sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("NTC Sicaklik", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("NTC Sıcaklık Sensörü Testi Başladı / NTC Temperature Sensor Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    float temp = iotbot.moduleNtcTempRead(SENSOR_PIN);
    // NTC sıcaklık sensöründen veri oku / Read data from the NTC temperature sensor

    iotbot.serialWrite("Sıcaklık / Temperature: ");
    iotbot.serialWrite(temp);
    // Seri porta sıcaklık değerini yazdır / Print temperature value to serial port

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Sicaklik:", "Temperature:", String(temp, 1).c_str(), "C");
    // Sıcaklık değerini LCD ekrana yazdır / Display temperature value on LCD

    delay(1000);
    // Yeni okuma yapmadan önce 1 saniye bekle / Wait for 1 second before reading again
}
