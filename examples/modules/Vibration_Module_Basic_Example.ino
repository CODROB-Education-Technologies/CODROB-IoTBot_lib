#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Titreşim sensör testi başlatıldı / Vibration sensor test started.");
}

void loop()
{
    int vibrationStatus = iotbot.moduleVibrationAnalogRead(IO27); // Titreşim durumu okunuyor / Read vibration status

    iotbot.serialWrite("Titresim Durumu / Vibration Status: ");
    iotbot.serialWrite(vibrationStatus); // Titreşim durumu yazdırılıyor / Print vibration status

    delay(100); // 500 ms bekle / Wait for 500 ms
}
