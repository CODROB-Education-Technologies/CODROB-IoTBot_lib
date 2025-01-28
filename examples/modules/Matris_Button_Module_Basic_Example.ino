#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Matris Buton", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int buttonNumber = iotbot.moduleMatrisButtonNumberRead(IO27); // Matris buton verisi / Matrix button value
    iotbot.lcdClear();

    if (buttonNumber > 0)
    {
        iotbot.lcdWriteMid("Buton:", "Button:", String(buttonNumber).c_str(), "");
    }
    else
    {
        iotbot.lcdWriteMid("Buton Basilmadi", "No Button Pressed", "", "");
    }

    delay(500);
}
