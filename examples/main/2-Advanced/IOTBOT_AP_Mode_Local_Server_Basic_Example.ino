#include <IOTBOT.h> // 📌 IoTBot Kütüphanesi / IoTBot Library

IOTBOT iotbot; // 📌 IoTBot Nesnesi / IoTBot Object

// 📌 **Web Sayfası İçeriği (HTML, CSS, JavaScript)**

// ✅ **JavaScript (Web Sayfası İçin)**
// Kullanıcı butona tıkladığında bir mesaj gösterecek.
const char WEBPageScript[] PROGMEM = R"rawliteral(
<script>
  function sayHello() {
    alert("Hello from IoTBot!");
  }
</script>
)rawliteral";

// ✅ **CSS (Web Sayfası Stili)**
// Web sayfasının görünümünü ayarlamak için CSS kullanıyoruz.
const char WEBPageCSS[] PROGMEM = R"rawliteral(
<style>
  body { text-align: center; font-family: Arial, sans-serif; }
  button { font-size: 20px; padding: 10px; margin: 20px; }
</style>
)rawliteral";

// ✅ **HTML (Web Sayfası İçeriği)**
// ESP32 tarafından sunulacak HTML kodu
const char WEBPageHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>IoTBot Web Server</title>
  %s <!-- CSS Dosyası Buraya Eklenir -->
  %s <!-- JavaScript Dosyası Buraya Eklenir -->
</head>
<body>
  <h1>IoTBot Web Sayfası</h1>
  <button onclick="sayHello()">Tıklayın</button>
</body>
</html>
)rawliteral";

// 📌 **Erişim Noktası (AP) Modu İçin Wi-Fi Bilgileri**
const char *ap_ssid = "CODROB Server"; // 📌 AP Modu için SSID / AP Mode SSID
const char *ap_password = "12345678";  // 📌 AP Modu için Şifre / AP Mode Password (En az 8 karakter)

// 📌 **Kurulum Fonksiyonu (Setup)**
void setup()
{
  iotbot.serialStart(115200); // 📌 **Seri Haberleşmeyi Başlat / Start Serial Communication**

  // 📌 **ESP32'yi Erişim Noktası (AP) Olarak Başlat**
  iotbot.serverStart("AP", ap_ssid, ap_password);

  // 📌 **ESP32 Üzerinde Web Sayfasını Yayınla**
  iotbot.serverCreateLocalPage("dashboard", WEBPageScript, WEBPageCSS, WEBPageHTML);
}

// 📌 **Ana Döngü (Loop)**
void loop()
{
  iotbot.serverContinue(); // 📌 **AP modunda DNS yönlendirmeyi sürdür**
}
