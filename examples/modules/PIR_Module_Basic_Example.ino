#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("PIR Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int motionDetected = iotbot.moduleMotionRead(IO27); // PIR sensör verisi / PIR sensor value
    iotbot.lcdClear();

    if (motionDetected)
    {
        iotbot.lcdWriteMid("Hareket Algılandi!", "Motion Detected!", "", "");
    }
    else
    {
        iotbot.lcdWriteMid("Hareket Yok", "No Motion", "", "");
    }

    delay(500);
}
