#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // DHT sensörünün bağlı olduğu pini seçin / Select the pin connected to the DHT sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("DHT sensör testi başlatıldı / DHT sensor test started.");
    // Hoşgeldiniz mesajını seri porta yazdır / Display test start message on the serial port

    iotbot.lcdClear(); // LCD ekranını temizle / Clear the LCD screen

    iotbot.lcdWriteMid("DHT Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int temperature = iotbot.moduleDhtTempReadC(SENSOR_PIN);
    // DHT sensöründen sıcaklık verisini oku / Read temperature data from the DHT sensor

    int humidity = iotbot.moduleDhtHumRead(SENSOR_PIN);
    // DHT sensöründen nem verisini oku / Read humidity data from the DHT sensor

    iotbot.serialWrite("Sıcaklık / Temperature: ");
    iotbot.serialWrite(temperature);
    // Sıcaklık değerini seri porta yazdır / Print temperature value to the serial port

    iotbot.serialWrite("Nem / Humidity: ");
    iotbot.serialWrite(humidity);
    // Nem değerini seri porta yazdır / Print humidity value to the serial port

    iotbot.lcdClear(); // LCD ekranını temizle / Clear the LCD screen

    iotbot.lcdWriteMid(
        "DHT Sensor",
        ("Temp: " + String(temperature) + "°C").c_str(),
        ("Humidity: " + String(humidity) + "%").c_str(),
        ""); // LCD'ye sıcaklık ve nem değerlerini yazdır / Display temperature and humidity values on the LCD

    delay(2000);
    // Yeni veri okumadan önce 2 saniye bekle / Wait for 2 seconds before reading new data
}
