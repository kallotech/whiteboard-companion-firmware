# Camera selection checklist

The user selected an ESP32-S3 camera path. The initial firmware reference is an ESP32-S3-DevKitC-1 N8R8 plus an OV2640 DVP camera breakout with a 24-pin connector. This is a software target, not a confirmed purchase/SKU or fit-checked CAD component.

The OV2640 is supported by Espressif's `esp32-camera` driver on the ESP32-S3. A DVP breakout is not pin-compatible merely because it uses an OV2640 sensor: connector pin order, power rails, clock and control pins must match the actual module. The S3 N8R8 reference provides PSRAM for the initial SVGA JPEG configuration.

Before updating the CAD or firmware, confirm:

- Exact camera breakout SKU, sensor, lens, dimensions and FPC pin order
- Driver/library support for the selected ESP32-S3 and its maintenance status
- DVP data/control pins, reset/power-down pins, cable and connector requirements
- Supply voltage, peak current and logic levels
- Output format, maximum frame size and PSRAM needs
- Lens field of view and readable whiteboard coverage at the designed standoff
- Cable route, strain relief and optical-window clearances in R04

Firmware currently captures only when the physical button is pressed, logs frame size and discards the JPEG. It does not save or transmit images. Exact camera SKU, FPC routing and physical fit remain to be verified in Fusion before committing the CAD revision.

