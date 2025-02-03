#include <IOTBOT.h>

IOTBOT iotbot;

// 🔑 Firebase Configuration
#define FIREBASE_PROJECT_URL "https://smart-sound-001-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_API_KEY "AIzaSyAiAv2SvCZzX6xSqgFVkNfqXU1vm4aEuNQ"

// 📧 Firebase User Authentication
#define USER_EMAIL "kaya.samed@outlook.com"
#define USER_PASSWORD "SamCo1234"

void setup()
{
    iotbot.serialStart(115200); // Start Serial Communication
    Serial.println("🚀 IoTBot Firebase Example Starting...");

    // 🔗 Step 1: Connect to Wi-Fi
    iotbot.wifiStartAndConnect("INTERNET", "INTERNET_2022");

    // 🔥 Step 2: Initialize Firebase
    iotbot.fbServerSetandStart(FIREBASE_PROJECT_URL, FIREBASE_API_KEY);

    // ✅ Step 3: Authenticate User
    if (iotbot.fbServerUserVerification(USER_EMAIL, USER_PASSWORD))
    {
        Serial.println("✅ Firebase Authentication Successful!");
    }
    else
    {
        Serial.println("❌ Firebase Authentication Failed!");
    }
    String Online = "Online";
    // ✍️ Step 4: Send Data to Firebase
    iotbot.fbServerSetInt("/device/temperature", 25);
    iotbot.fbServerSetString("/device/status", Online);
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

    delay(5000); // Refresh every 5 seconds
}