#include <IOTBOT.h>

IOTBOT iotbot;

#define RELAY_PIN 27

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    // Röleyi aktif hale getir / Activate the relay
    iotbot.moduleRelayWrite(RELAY_PIN, true);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Açık / ON", "");
    delay(3000);

    // Röleyi pasif hale getir / Deactivate the relay
    iotbot.moduleRelayWrite(RELAY_PIN, false);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Kapalı / OFF", "");
    delay(3000);
}
