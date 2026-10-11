# Camera selection checklist

The current CAD includes an ESP32-C3 DevKit and an optical pod, but no camera component. Select a module before adding a hardware driver or pin assignments.

The ESP32-C3 does not use Espressif's standard parallel-camera `esp32-camera` driver. Keep the current controller only with a camera module and driver designed for an SPI connection. Prefer a module that provides JPEG capture or an onboard frame buffer so image acquisition does not depend on a large parallel frame buffer in the C3.

Before updating the CAD or firmware, confirm:

- Exact module, sensor, lens, dimensions and connector
- Driver/library support for ESP32-C3 and its maintenance status
- SPI pins, chip-select, reset and interrupt requirements
- Supply voltage, peak current and logic levels
- Output format, maximum frame size and memory needs
- Lens field of view and readable whiteboard coverage at the designed standoff
- Cable route, strain relief and optical-window clearances in R04

No image capture or image transmission is implemented until these choices and the capture workflow are reviewed.

