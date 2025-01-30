#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("🔊 Buzzer testi başlatıldı / Buzzer test started.");

    // **LCD başlangıç mesajı / LCD startup message**
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Buzzer Test", "--- IoTBot ---", "Test Basladi!", "Starting Test!");
    delay(2000); // Başlangıç için 2 saniye bekle / Wait 2 seconds for startup
}

void loop()
{
    // 🎵 **Farklı tonlar ve sürelerle buzzer çalma / Play buzzer with different tones and durations**
    int tones[][2] = {
        {1000, 300}, // **1000 Hz - 300 ms**
        {1500, 300}, // **1500 Hz - 300 ms**
        {2000, 300}, // **2000 Hz - 300 ms**
        {2500, 300}, // **2500 Hz - 300 ms**
    };

    // 🎼 **Her ton için döngüye gir / Loop through each tone**
    for (int i = 0; i < 4; i++)
    {
        int freq = tones[i][0];
        int duration = tones[i][1];

        // **Seri porta mesaj yazdır / Print message to serial port**
        iotbot.serialWrite("🎶 Buzzer playing at " + String(freq) + "Hz for " + String(duration) + "ms");

        // **LCD ekranı güncelle / Update LCD screen**
        iotbot.lcdClear();
        iotbot.lcdWriteMid("Buzzer Çalıyor", "Playing Tone", String(freq).c_str(), "Hz");

        // **Buzzer çal / Play buzzer**
        iotbot.buzzerPlayTone(freq, duration);
        delay(500); // 500 ms bekle / Wait 500 ms
    }

    // **1 saniye bekle ve tekrar et / Wait 1 second and repeat**
    delay(1000);
}
