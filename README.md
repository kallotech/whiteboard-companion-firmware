# Whiteboard Companion

Firmware companion for an open hardware concept that helps teams carry whiteboard ideas forward.

> **Prototype status:** this is an early firmware scaffold, not working camera or AI hardware. The current Fusion design includes an ESP32-C3 DevKit reference, but no camera module or pin map has been selected.

## Project links

- [Partwork project and editable CAD](https://partwork.co/project/ai-whiteboard-assistant)
- [Camera selection notes](docs/camera-selection.md)

## Current firmware

The starter project targets an ESP32-C3 DevKit using PlatformIO and Arduino. It boots and reports that the camera is not configured. `CameraAdapter` defines the seam for a future module-specific JPEG capture driver; it intentionally does not fake camera support.

Camera capture and any AI workflow are not implemented. No images are captured or sent anywhere.

## Build

1. Install PlatformIO Core or the PlatformIO IDE extension.
2. Open this folder as a PlatformIO project.
3. Build the `esp32-c3-devkitm-1` environment and connect a compatible board to view the serial log at 115200 baud.

The CAD source uses the generic name ESP32-C3 DevKit; confirm the exact physical board variant before relying on the environment or adding pin assignments.

## Contributing

Keep the hardware target and camera model explicit in changes. Never commit Wi-Fi credentials, access tokens or real whiteboard captures. Record the board, camera module and library versions used for any hardware result.

Firmware is licensed under MIT. The hardware design has its own license on Partwork.

