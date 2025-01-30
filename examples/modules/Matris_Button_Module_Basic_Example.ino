#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

// IoTBot nesnesi oluşturuluyor / Create an IoTBot object
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Matris butonunun bağlı olduğu pini seçin / Select the pin connected to the matrix button
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin(); // IoTBot başlatılıyor / Initialize IoTBot

    iotbot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    iotbot.lcdWriteMid("Matris Buton", "--- IoTBot ---", "Test Basladi", "Test Started");
    // LCD'ye test başladığını yazdır / Display test start message on LCD

    iotbot.serialWrite("Matris Buton Testi Başlatıldı / Matrix Button Test Started.");
    // Test başladığını seri porta yazdır / Print test start message to the serial port

    delay(3000); // Başlangıç için bekleme süresi / Initial delay
}

void loop()
{
    int buttonNumber = iotbot.moduleMatrisButtonNumberRead(SENSOR_PIN);
    // Matris buton verisini oku / Read matrix button value

    iotbot.lcdClear(); // LCD ekranı temizle / Clear the LCD screen

    if (buttonNumber > 0)
    {
        iotbot.lcdWriteMid("Buton:", "Button:", String(buttonNumber).c_str(), "");
        // Basılan buton numarasını LCD ekrana yazdır / Display pressed button number on LCD

        iotbot.serialWrite("Basılan Buton / Pressed Button: " + String(buttonNumber));
        // Seri porta basılan buton numarasını yazdır / Print pressed button number to the serial port
    }
    else
    {
        iotbot.lcdWriteMid("Buton Basilmadi", "No Button Pressed", "", "");
        // Eğer butona basılmadıysa ekrana mesaj yazdır / Display "No Button Pressed" message on LCD

        iotbot.serialWrite("Herhangi bir butona basılmadı / No button pressed.");
        // Seri porta butona basılmadığını yazdır / Print "No button pressed" message to the serial port
    }

    delay(500); // Yeni okuma yapmadan önce 500 ms bekle / Wait for 500 ms before reading again
}
