#include "BleSecurityStatus.h"

#include <Arduino.h>

BleSecurityStatus::BleSecurityStatus(void) {
}

uint32_t BleSecurityStatus::onPassKeyRequest() {
    Serial.println("PassKey Request");
    return 123456;
}

void BleSecurityStatus::onPassKeyNotify(uint32_t pass_key) {
    Serial.print("The passkey Notify number: ");
    Serial.println(pass_key);
}

bool BleSecurityStatus::onConfirmPIN(uint32_t pass_key) {
    Serial.print("The passkey YES/NO number: ");
    Serial.println(pass_key);
    vTaskDelay(5000);
    return true;
}

bool BleSecurityStatus::onSecurityRequest() {
    this->authenticated = false;
    Serial.println("Security Request");
    return true;
}

void BleSecurityStatus::onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl) {
    Serial.println("Authentication Complete");
    this->authenticated = true;
}