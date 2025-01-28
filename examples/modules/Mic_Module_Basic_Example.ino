#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Mikrofon Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int micValue = iotbot.moduleMicRead(IO27); // Mikrofon sensör verisi / Microphone sensor value
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Mikrofon Degeri:", "", String(micValue).c_str(), "");
    delay(500); // Gecikme / Delay
}
