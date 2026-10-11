# Status — 11 October 2026

## Implemented in this starter

- PlatformIO project scaffold targeting an ESP32-C3 DevKit variant.
- Serial startup message and a camera adapter interface.
- Safe unconfigured camera implementation; it reports that capture is unavailable.

## Not implemented or verified

- Camera hardware/driver, pin assignments, JPEG capture, Wi-Fi, image transfer, AI service and physical controls.
- The CAD names the board only as ESP32-C3 DevKit. Confirm the exact board variant before relying on the PlatformIO target.
- No hardware build or board test has been run.

## Next decision

Select a C3-compatible SPI camera module and verify its dimensions, optics and electrical requirements against the R04 camera pod and carrier PCB. See `docs/camera-selection.md`.

