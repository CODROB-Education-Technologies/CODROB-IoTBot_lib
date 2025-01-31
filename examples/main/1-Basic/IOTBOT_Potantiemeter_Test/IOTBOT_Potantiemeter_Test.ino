#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);

    iotbot.lcdClear();
    iotbot.lcdWriteMid("Potansiyometre", "--- IoTBot ---", "Başlatıldı!", "Started!");
    iotbot.serialWrite("🎚 Potansiyometre testi başlatıldı / Potentiometer test started.");

    delay(3000);
}

void loop()
{
    int potValue = iotbot.potentiometerRead();

    iotbot.serialWrite("🎚 Potansiyometre Değeri / Potentiometer Value: " + String(potValue));

    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "Potansiyometre Test");
    iotbot.lcdWriteCR(0, 1, "Deger:");
    iotbot.lcdWriteCR(7, 1, String(potValue));

    delay(500);
}
