#include <IOTBOT.h>

// IOTBOT nesnesi oluştur / Create an IOTBOT object
IOTBOT iotbot;

void setup()
{
  // IOTBOT başlat / Initialize IOTBOT
  iotbot.begin();

  // LCD ekranda başlangıç mesajı / Display startup message on LCD
  iotbot.lcdClear();
  iotbot.lcdWriteMid("IoTBot Disco!", "CODROB Style", "Let's Dance!", "");
  delay(2000);
}

void loop()
{
  // LCD mesajını temizle ve şovu başlat / Clear LCD and start the show
  iotbot.lcdClear();
  iotbot.lcdWriteMid("Enjoy the", "CODROB Beat!", "Dance Now!", "");

  // Ankara havası ritmi için tonlar, süreler ve LED pinleri / Tones, durations, and LED pins for Ankara beat
  int ritimTonlari[] = {
      600, 800, 600, 700, 900, 700, 800, 600,
      700, 600, 500, 700, 800, 600, 500, 600};
  int delayTimes[] = {
      150, 150, 150, 200, 150, 200, 150, 300,
      200, 150, 150, 200, 250, 150, 100, 400};
  int ledPins[] = {IO25, IO26, IO27, IO32, IO33}; // LED pinleri / LED pins

  // Ritim ve LED gösterisi / Rhythm and LED show
  for (int i = 0; i < 16; i++)
  {
    // LED'leri sırayla yak ve söndür / Turn LEDs on and off sequentially
    int currentLed = ledPins[i % 5];
    iotbot.digitalWritePin(currentLed, HIGH);

    // Buzzer çalsın / Play buzzer
    iotbot.buzzerPlayTone(ritimTonlari[i], delayTimes[i]);

    // Röle tetiklemesi sadece belirli adımlarda / Trigger relay at specific steps
    if (i % 8 == 0)
    {                           // Röle sadece her 8 adımda bir tetiklenir / Trigger relay every 8 steps
      iotbot.relayWrite(true);  // Röleyi aç / Turn relay on
      delay(50);                // Kısa bir vurgu için bekle / Short emphasis
      iotbot.relayWrite(false); // Röleyi kapat / Turn relay off
    }

    // LED'i kapat ve bir sonraki adımı bekle / Turn off LED and wait for the next step
    delay(delayTimes[i]);
    iotbot.digitalWritePin(currentLed, LOW);
  }

  // Final mesajı LCD'ye yaz / Display final message on LCD
  iotbot.lcdClear();
  iotbot.lcdWriteMid("That's It!", "IoTBot Disco", "", "See You Again!");
  delay(3000);
}
