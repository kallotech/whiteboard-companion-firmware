#include <Arduino.h>

#include "UnconfiguredCamera.h"

namespace {
UnconfiguredCamera camera;

const char* statusText(CameraStatus status) {
  switch (status) {
    case CameraStatus::Ready:
      return "ready";
    case CameraStatus::CaptureFailed:
      return "capture failed";
    case CameraStatus::NotConfigured:
    default:
      return "not configured: select a camera module and pin map";
  }
}
}  // namespace

void setup() {
  Serial.begin(115200);
  delay(300);

  Serial.println("Whiteboard Companion firmware");
  Serial.println("Prototype scaffold; no camera is selected or initialized.");
  Serial.printf("Camera: %s\n", statusText(camera.begin()));
}

void loop() { delay(1000); }

