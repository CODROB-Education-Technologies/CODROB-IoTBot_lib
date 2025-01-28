#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Duman Sensoru", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int smokeLevel = iotbot.moduleSmokeRead(IO27); // Duman sensörü verisi / Smoke sensor value
    iotbot.lcdClear();

    if (smokeLevel > 1400)
    { // Kritik eşik / Critical threshold
        iotbot.lcdWriteMid("Duman Algilandi!", "Smoke Detected!", "", "");
    }
    else
    {
        iotbot.lcdWriteMid("Duman Yok", "No Smoke", "Seviye: ", String(smokeLevel).c_str());
    }

    delay(1000); // 1 saniye gecikme / 1 second delay
}
