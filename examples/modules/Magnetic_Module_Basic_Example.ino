#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Manyetik sensörün bağlı olduğu pini seçin / Select the pin connected to the magnetic sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("Manyetik sensör testi başlatıldı / Magnetic sensor test started.");
    // Manyetik sensör testinin başladığını seri porta yazdır / Display test start message on the serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Manyetik Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int magneticStatus = iotbot.moduleMagneticRead(SENSOR_PIN);
    // Manyetik sensörün durumunu oku / Read magnetic sensor status

    iotbot.serialWrite("Manyetik Sensör Durumu / Magnetic Sensor Status: ");
    iotbot.serialWrite(magneticStatus ? "Tespit Edildi / Detected" : "Yok / Not Detected");
    // Manyetik alan algılandıysa "Tespit Edildi", aksi halde "Yok" yazdır
    // Print "Detected" if a magnetic field is detected, otherwise print "Not Detected"

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    if (magneticStatus)
    {
        iotbot.lcdWriteMid("Manyetik Alan", "Tespit Edildi!", "Magnetic Field", "Detected!");
        // Manyetik alan algılandığında LCD'ye uyarı yazdır / Display warning if a magnetic field is detected

        iotbot.serialWrite("⚠️ Manyetik Alan Algılandı! / ⚠️ Magnetic Field Detected!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Manyetik Alan", "Yok", "Magnetic Field", "Not Detected");
        // Manyetik alan yoksa LCD'ye bilgi yazdır / Display "Not Detected" if no magnetic field is found

        iotbot.serialWrite("Manyetik Alan Yok / No Magnetic Field");
        // Seri porta normal durum mesajı yazdır / Print normal status message to serial port
    }

    delay(500); // Yeni okuma yapmadan önce 500 ms bekle / Wait for 500 ms before reading again
}
