# Context

This repository is for the embedded side of the Whiteboard Companion, an AI-assisted whiteboard concept.

The current mechanical source is `../Revision-04-Mouldability/Whiteboard-Companion-Slim-R04.f3d`. R04 contains a supplied ESP32-C3 DevKit reference and a separate camera pod. The user has selected an ESP32-S3 camera direction; firmware now uses the ESP32-S3-DevKitC-1 N8R8 and OV2640 DVP as provisional reference parts. The Fusion CAD/BOM still needs a revision to replace the C3 envelope and confirm the camera board, connector, cable route and fit. The Fusion CAD/BOM is authoritative for mechanical packaging; this repository is authoritative for firmware source.

Firmware uses PlatformIO/Arduino and Espressif's `esp32-camera` driver. Keep board/camera details behind `CameraAdapter`; the current pin map is a reference pending confirmation against the exact module and carrier wiring.

