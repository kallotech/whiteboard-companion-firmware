# Status — 12 October 2026

## Implemented in this starter

- PlatformIO project targeting an ESP32-S3-DevKitC-1 N8R8 reference.
- Espressif `esp32-camera` initialization for a reference OV2640 DVP pin map.
- Physical capture-button handler; captured JPEG size is logged and frame memory is released.
- MIT firmware license.

## Not implemented or verified

- Exact DevKitC-1 and camera breakout SKUs, connector/pinout and wiring have not been confirmed.
- R04 CAD still contains the earlier ESP32-C3 reference; no S3/camera fit check has been made.
- Wi-Fi, image storage/transfer, AI service and camera optics are not implemented.
- No firmware build or board test has been run.

## Next decision

Confirm the exact DevKitC-1 N8R8 and OV2640 DVP camera breakout, then update the Fusion model and verify dimensions, optics, FPC routing and electrical requirements. See `docs/camera-selection.md`.

