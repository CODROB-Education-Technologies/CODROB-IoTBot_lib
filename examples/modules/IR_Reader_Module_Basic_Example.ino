#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33
void setup()
{
    iotbot.begin();             // Initialize IoTBot / IoTBot başlatılıyor
    iotbot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
    iotbot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat

    iotbot.serialWrite("Welcome to IoTBot IR Reader Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
}
