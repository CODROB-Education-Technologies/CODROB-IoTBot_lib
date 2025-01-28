#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Toprak nem sensör testi başlatıldı / Soil moisture sensor test started.");
}

void loop()
{
    int soilMoisture = iotbot.moduleSoilMoistureRead(IO27); // Toprak nem değeri okunuyor / Read soil moisture value

    iotbot.serialWrite("Toprak Nem Değeri / Soil Moisture Value: ");
    iotbot.serialWrite(soilMoisture); // Toprak nem değeri yazdırılıyor / Print soil moisture value

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
