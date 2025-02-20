#include <IOTBOT.h>

IOTBOT iotbot;

// 🔑 Firebase Configuration | 🔑 Firebase Yapılandırması
#define FIREBASE_PROJECT_URL "https://deneme-961c3-default-rtdb.firebaseio.com/" // Enter the Firebase server URL here. | Buraya Firebase sunucusunun linkini yazınız.
#define FIREBASE_API_KEY "AIzaSyA5wTuxzls6IxQct-G2_hf0i5LWF3ulsec"               // Enter the Firebase server API key here. | Buraya Firebase sunucusunun API anahtarını yazınız.

// 📧 Firebase User Authentication | 📧 Firebase Kullanıcı Kimlik Doğrulama
#define USER_EMAIL "deneme123@gmail.com" // Enter the email address used to create the Firebase user here. | Buraya Firebase sunucusunda oluşturduğunuz kullanıcı e-posta adresini yazınız.
#define USER_PASSWORD "dene123"          // Enter the password for the Firebase user here. | Buraya Firebase sunucusunda oluşturduğunuz kullanıcı şifresini yazınız.

// 📡 WiFi Settings | 📡 WiFi Ayarları
#define WIFI_SSID "WIFI_SSID" // Enter the name of the Wi-Fi network you want to connect to here. | Buraya bağlanmak istediğiniz Wi-Fi ağının adını yazınız.
#define WIFI_PASS "WiFi_PASS" // Enter the password of the Wi-Fi network you want to connect to here. | Buraya bağlanmak istediğiniz Wi-Fi ağının şifresini yazınız.

void setup()
{
    iotbot.serialStart(115200); // Start Serial Communication
    Serial.println("🚀 IoTBot Firebase Example Starting...");

    // 🔗 Step 1: Connect to Wi-Fi
    iotbot.wifiStartAndConnect(WIFI_SSID, WIFI_PASS);

    if (!iotbot.wifiConnectionControl())
    {
        iotbot.serialWrite("Device Stopped!");
        while (true) // Endless loop | Sonsuz döngü
        {
            if (iotbot.wifiConnectionControl())
            {
                iotbot.serialWrite("Connection Success! Reworking..");
                break; // Exit the loop, continue.| Döngüden çık, devam et.
            }
        }
    }

    // 🔥 Step 2: Initialize Firebase
    iotbot.fbServerSetandStartWithUser(FIREBASE_PROJECT_URL, FIREBASE_API_KEY, USER_EMAIL, USER_PASSWORD);

    // ✍️ Step 3: Send Data to Firebase
    iotbot.fbServerSetInt("/device/temperature", 25);
    iotbot.fbServerSetString("/device/status", "Online");
    iotbot.fbServerSetBool("/device/active", true);

    Serial.println("📤 Data sent to Firebase.");
}

void loop()
{
    // 🔄 Step 5: Read Data from Firebase
    int temp = iotbot.fbServerGetInt("/device/temperature");
    String status = iotbot.fbServerGetString("/device/status");
    bool active = iotbot.fbServerGetBool("/device/active");

    // 🖨️ Display Data on Serial Monitor
    Serial.print("🌡️ Temperature: ");
    Serial.println(temp);

    Serial.print("💡 Status: ");
    Serial.println(status);

    Serial.print("🔋 Active: ");
    Serial.println(active ? "Yes" : "No");

    delay(60000); // Refresh every 5 seconds
}