# Whiteboard Companion

Firmware companion for an open hardware concept that helps teams carry whiteboard ideas forward.

> **Prototype status:** this firmware now has a reference capture path for an ESP32-S3-DevKitC-1 N8R8 and an OV2640 DVP camera. The camera/module wiring is a provisional reference and has not been built or tested. The current Fusion R04 model still contains the older ESP32-C3 reference.

## Project links

- [Partwork project and editable CAD](https://partwork.co/project/ai-whiteboard-assistant)
- [Camera wiring and selection notes](docs/camera-selection.md)

## Current firmware

The starter project targets an ESP32-S3-DevKitC-1 N8R8 using PlatformIO and Arduino. It initializes the Espressif camera driver with an OV2640 DVP reference pin map, then captures a JPEG when the capture button is pressed. It reports the image size over serial and discards the frame; it does not save or transmit images.

The reference wiring must be checked against the exact camera breakout and DevKitC-1 variant. No Wi-Fi, image transfer, or AI workflow is implemented.

## Build

1. Install PlatformIO Core or the PlatformIO IDE extension.
2. Open this folder as a PlatformIO project.
3. Use an ESP32-S3-DevKitC-1 N8R8 and a compatible 24-pin OV2640 DVP camera breakout. Connect the capture button between GPIO1 and GND.
4. Build the `esp32-s3-devkitc-1` environment and connect the board to view the serial log at 115200 baud.

The selected firmware target needs PSRAM for SVGA JPEG capture. R04 CAD still uses a generic ESP32-C3 board; its electronics packaging must be revised before treating the S3/camera fit as verified.

## Contributing

Keep the hardware target and camera model explicit in changes. Never commit Wi-Fi credentials, access tokens or real whiteboard captures. Record the board, camera module and library versions used for any hardware result.

Firmware is licensed under MIT. The hardware design has its own license on Partwork.

