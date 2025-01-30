#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Toprak nem sensörünün bağlı olduğu pini seçin / Select the pin connected to the soil moisture sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Toprak nem sensör testi başlatıldı / Soil moisture sensor test started.");
    // Test başladığını seri porta yazdır / Print test start message to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Toprak Nem Sensoru", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int soilMoisture = iotbot.moduleSoilMoistureRead(SENSOR_PIN);
    // Toprak nem sensöründen veri oku / Read data from the soil moisture sensor

    iotbot.serialWrite("Toprak Nem Değeri / Soil Moisture Value: ");
    iotbot.serialWrite(soilMoisture);
    // Seri porta toprak nem değerini yazdır / Print soil moisture value to serial port

    iotbot.lcdClear();
    // LCD ekranı temizle / Clear the LCD screen

    if (soilMoisture < 500) // Düşük nem seviyesi kontrolü / Check for low moisture level
    {
        iotbot.lcdWriteMid("Toprak Kurak!", "Soil Dry!", "Nem: ", String(soilMoisture).c_str());
        // Nem seviyesi düşükse LCD'de uyarı göster / Display warning if soil is dry

        iotbot.serialWrite("⚠️ Toprak kuru! / Soil is dry!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Toprak Nemli", "Soil Moist", "Nem: ", String(soilMoisture).c_str());
        // Toprak yeterince nemliyse LCD'de göster / Display moisture level on LCD

        iotbot.serialWrite("Toprak yeterince nemli / Soil is sufficiently moist.");
        // Seri porta durumu yazdır / Print status message to serial port
    }

    delay(1000);
    // Yeni okuma yapmadan önce 1 saniye bekle / Wait for 1 second before reading again
}
