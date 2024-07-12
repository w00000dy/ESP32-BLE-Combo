#ifndef ESP32_BLE_SECURITY_STATUS_H
#define ESP32_BLE_SECURITY_STATUS_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include <BLESecurity.h>

class BleSecurityStatus : public BLESecurityCallbacks {
public:
  BleSecurityStatus(void);
  bool authenticated = false;
  uint32_t onPassKeyRequest();
  void onPassKeyNotify(uint32_t pass_key);
  bool onSecurityRequest();
  void onAuthenticationComplete(esp_ble_auth_cmpl_t);
  bool onConfirmPIN(uint32_t pin);
};

#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_SECURITY_STATUS_H
