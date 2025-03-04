#ifndef USE_WIFI_H
#define USE_WIFI_H

/**
 * @file USE_WIFI.h
 * @brief IOTBOT modüllerinin etkinleştirilmesi/devre dışı bırakılması için yapılandırma dosyası.
 * @brief Configuration file for enabling/disabling IOTBOT modules.
 *
 * Kullanılacak modülleri etkinleştirmek için `#define` satırını açın.
 * Devre dışı bırakılan modüller derlemeden hariç tutulur, hafıza kullanımı optimize edilir.
 * Activate desired modules by uncommenting `#define` lines.
 * Disabled modules are excluded from compilation, optimizing memory usage.
 *
 * ------------------------------
 * Avantajlar / Benefits:
 * ------------------------------
 * ✅ Bellek kullanımını azaltır. / Reduces memory usage.
 * ✅ Modüler ve yönetimi kolaydır. / Modular and easy to manage.
 * ✅ Derleme süresini optimize eder. / Optimized compilation time.
 */

// Modülleri etkinleştir/devre dışı bırak
// Enable/disable modules
// Etkinleştirmek için yorumu kaldırın / Uncomment to activate

#define USE_WIFI // WiFi desteğini etkinleştir / Enable WiFi support

#endif // USE_WIFI_H
