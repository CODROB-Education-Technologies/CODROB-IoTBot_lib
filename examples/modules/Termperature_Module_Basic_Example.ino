#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("NTC Sicaklik", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    float temp = iotbot.moduleNtcTempRead(IO27); // NTC sıcaklık değeri / NTC temperature value
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Sicaklik:", "Temperature:", String(temp, 1).c_str(), "C");
    delay(1000); // 1 saniyelik gecikme / 1 second delay
}
