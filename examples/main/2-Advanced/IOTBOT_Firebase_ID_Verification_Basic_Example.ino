#include <IOTBOT.h>

IOTBOT iotbot;

// 🔑 Firebase Configuration
#define FIREBASE_PROJECT_URL "https://smart-sound-001-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_API_KEY "AIzaSyAiAv2SvCZzX6xSqgFVkNfqXU1vm4aEuNQ"

// 📧 Firebase User Authentication
#define USER_EMAIL "kaya.samed@outlook.com"
#define USER_PASSWORD "SamCo1234"

// 📧 WiFi Settings
#define WIFI_SSID "INTERNET"
#define WiFi_PASS "INTERNET_2022"

void setup()
{
    iotbot.serialStart(115200); // Start Serial Communication
    Serial.println("🚀 IoTBot Firebase Example Starting...");

    // 🔗 Step 1: Connect to Wi-Fi
    iotbot.wifiStartAndConnect(WIFI_SSID, WiFi_PASS);

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