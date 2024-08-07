# ESP32 BLE Combo Keyboard & Mouse library

This library allows you to make the ESP32 act as a Bluetooth keyboard and mouse with Arduino.

You might also be interested in:

- [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
- [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard)
- [ESP32-BLE-Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad)
## Todo

 - [x] Send key strokes
 - [x] Send text
 - [x] Press/release individual keys
 - [x] Media keys are supported
 - [ ] Read Numlock/Capslock/Scrolllock state
 - [ ] Add gamepad support
 - [x] Auto-instantiate Keyboard, Mouse objects (like the standard Arduino libraries)
 - [ ] Optimize so that only needed classes get created for BLE.
 - [x] Compatible with Android
 - [x] Compatible with Windows
 - [x] Compatible with Linux
 - [x] Compatible with MacOS X (not stable, some people have issues, doesn't work with old devices)
 - [x] Compatible with iOS (not stable, some people have issues, doesn't work with old devices)

## Installation
- (Make sure you can use the ESP32 with the Arduino IDE. [Instructions can be found here.](https://github.com/espressif/arduino-esp32#installation-instructions))
- [Download the latest release of this library from the release page.](https://github.com/ServAlex/ESP32-BLE-Combo/releases)
Arduino IDE:
- In the Arduino IDE go to "Sketch" -> "Include Library" -> "Add .ZIP Library..." and select the file you just downloaded.
- You can now go to "File" -> "Examples" -> "ESP32 BLE Combo" and select any of the examples to get started.
VS Code:
- In VS Code you can unzip downloaded .ZIP to your libraries directory (listed in your "includePath").

## Example

```c++
#include <Arduino.h>
#include <BleCombo.h>

void setup() {
    Serial.begin(115200);
    Keyboard.begin();
    Mouse.begin();

    Serial.println("The Bluetooth Device Is Ready To Pair");

    // wait until client is connected
    while (!Keyboard.isAuthenticated()) {
        delay(100);
    }

    Serial.println("The Bluetooth Device Is Connected Successfully");
}

void loop() {
    if (Keyboard.isConnected()) {
        Serial.println("Move mouse pointer up");
        for (uint8_t i = 50; i > 0; i--) {
            Mouse.move(0, -10);
            delay(10);
        }

        delay(1000);

        Serial.println("Move mouse pointer down");
        for (uint8_t i = 50; i > 0; i--) {
            Mouse.move(0, 10);
            delay(10);
        }
    }

    Serial.println("Waiting 2 seconds...");
    delay(2000);
}

```
## Credits
This is a fork of @blackketter's fork of @T-kV's excellent [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
and [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) libraries with fixes backported (up to December 2020).
