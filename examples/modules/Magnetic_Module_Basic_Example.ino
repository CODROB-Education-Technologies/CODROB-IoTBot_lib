#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Manyetik sensör testi başlatıldı / Magnetic sensor test started.");
}

void loop()
{
    int magneticStatus = iotbot.moduleMagneticRead(IO27); // Manyetik sensör durumu okunuyor / Read magnetic sensor status

    iotbot.serialWrite("Manyetik Sensör Durumu / Magnetic Sensor Status: ");
    iotbot.serialWrite(magneticStatus); // Manyetik sensör durumu yazdırılıyor / Print magnetic sensor status

    delay(500); // 500 ms bekle / Wait for 500 ms
}
