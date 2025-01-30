#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // PIR sensörünün bağlı olduğu pini seçin / Select the pin connected to the PIR sensor
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.serialWrite("PIR Sensör Testi Başlatıldı / PIR Sensor Test Started.");
    // PIR sensör testinin başladığını seri porta yazdır / Print PIR sensor test start message to the serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("PIR Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int motionDetected = iotbot.moduleMotionRead(SENSOR_PIN);
    // PIR sensöründen hareket algılama verisini oku / Read motion detection data from PIR sensor

    iotbot.serialWrite("PIR Sensör Durumu / PIR Sensor Status: " + String(motionDetected ? "Hareket Algılandı / Motion Detected" : "Hareket Yok / No Motion"));
    // Hareket durumu bilgisini seri porta yazdır / Print motion status to serial port

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    if (motionDetected)
    {
        iotbot.lcdWriteMid("⚠️ Hareket Algılandi!", "⚠️ Motion Detected!", "", "");
        // Eğer hareket algılandıysa mesajı LCD ekrana yazdır / Display message on LCD if motion is detected

        iotbot.serialWrite("⚠️ PIR Sensör Hareket Algıladı! / ⚠️ PIR Sensor Detected Motion!");
        // Seri porta uyarı mesajı yazdır / Print warning message to serial port
    }
    else
    {
        iotbot.lcdWriteMid("Hareket Yok", "No Motion", "", "");
        // Eğer hareket algılanmadıysa mesajı LCD ekrana yazdır / Display message on LCD if no motion is detected

        iotbot.serialWrite("PIR Sensör Hareket Algılamadı / PIR Sensor Detected No Motion");
        // Seri porta bilgilendirme mesajı yazdır / Print no motion detected message to serial port
    }

    delay(500); // Yeni okuma yapmadan önce 500 ms bekle / Wait for 500 ms before reading again
}
