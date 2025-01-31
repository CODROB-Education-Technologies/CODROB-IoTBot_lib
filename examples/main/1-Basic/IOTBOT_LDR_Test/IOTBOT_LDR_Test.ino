#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);

    iotbot.lcdClear();
    iotbot.lcdWriteMid("LDR Test", "--- IoTBot ---", "Başlatıldı!", "Started!");
    iotbot.serialWrite("💡 LDR testi başlatıldı / LDR test started.");

    delay(3000);
}

void loop()
{
    int ldrValue = iotbot.ldrRead();

    iotbot.serialWrite("💡 LDR Değeri / LDR Value: " + String(ldrValue));

    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "LDR Test");
    iotbot.lcdWriteCR(0, 1, "LDR Degeri:");
    iotbot.lcdWriteCR(10, 1, String(ldrValue));

    delay(500);
}
