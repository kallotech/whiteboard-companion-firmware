# Context

This repository is for the embedded side of the Whiteboard Companion, an AI-assisted whiteboard concept.

The current mechanical source is `../Revision-04-Mouldability/Whiteboard-Companion-Slim-R04.f3d`. R04 contains a supplied ESP32-C3 DevKit reference and a separate camera pod, but the camera module, image processor, carrier routing, wiring and image workflow have not been selected. The Fusion CAD/BOM is authoritative for mechanical packaging; this repository is authoritative for firmware source.

The initial firmware uses PlatformIO/Arduino for a simple ESP32-C3 starter. Keep board-specific camera details behind `CameraAdapter` and do not assign camera pins until a module is selected and checked against the CAD.

