#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.serialWrite("🔌 Röle testi başlatıldı / Relay test started.");
}

void loop()
{
    iotbot.serialWrite("🔌 Röle açık / Relay ON.");
    iotbot.relayWrite(true);
    delay(2000);

    iotbot.serialWrite("🔌 Röle kapalı / Relay OFF.");
    iotbot.relayWrite(false);
    delay(2000);
}
