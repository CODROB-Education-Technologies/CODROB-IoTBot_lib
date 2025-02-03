#include <IOTBOT.h>

IOTBOT iotbot;

// 🔑 Firebase Configuration
#define FIREBASE_PROJECT_URL "https://smart-sound-001-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_API_KEY "AIzaSyAiAv2SvCZzX6xSqgFVkNfqXU1vm4aEuNQ"

// 🔑 WiFi Configuration
#define Your_WiFi_SSID "INTERNET"
#define Your_WiFi_Password "INTERNET_2022"

void setup()
{
    iotbot.serialStart(115200);
    Serial.println("🚀 IoTBot Firebase Example (Without Authentication)");

    // 🔗 Connect to Wi-Fi
    iotbot.wifiStartAndConnect(Your_WiFi_SSID, Your_WiFi_Password);

    // 🔥 Initialize Firebase (No User Authentication Required)
    iotbot.fbServerSetandStart(FIREBASE_PROJECT_URL, FIREBASE_API_KEY);

    // ✍️ Send Data to Firebase
    iotbot.fbServerSetInt("/device/temperature", 28);
    iotbot.fbServerSetString("/device/status", String("Online"));
    iotbot.fbServerSetBool("/device/active", true);

    Serial.println("📤 Data sent to Firebase.");
}

void loop()
{
    // 🔄 Read Data from Firebase
    int temp = iotbot.fbServerGetInt("/device/temperature");
    String status = iotbot.fbServerGetString("/device/status");
    bool active = iotbot.fbServerGetBool("/device/active");

    // 🖨️ Display Data
    Serial.print("🌡️ Temperature: ");
    Serial.println(temp);

    Serial.print("💡 Status: ");
    Serial.println(status);

    Serial.print("🔋 Active: ");
    Serial.println(active ? "Yes" : "No");

    delay(5000);
}
