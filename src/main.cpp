#include <Arduino.h>

#include "Ov2640Camera.h"

namespace {
constexpr uint8_t kCaptureButtonPin = 1;
Ov2640Camera camera;
bool cameraReady = false;
bool buttonLatched = false;

const char* statusText(CameraStatus status) {
  switch (status) {
    case CameraStatus::Ready:
      return "ready";
    case CameraStatus::CaptureFailed:
      return "capture failed";
    case CameraStatus::InitializationFailed:
    default:
      return "initialization failed";
  }
}

void captureOnButtonPress() {
  CaptureSummary summary;
  const CameraStatus status = camera.captureJpeg(summary);
  if (status != CameraStatus::Ready) {
    Serial.printf("Capture failed: %s\n", statusText(status));
    return;
  }

  // The prototype reports frame size only. It does not save or transmit images.
  Serial.printf("Captured JPEG (%u bytes); image was discarded.\n",
                static_cast<unsigned>(summary.jpegBytes));
}
}  // namespace

void setup() {
  Serial.begin(115200);
  delay(300);

  Serial.println("Whiteboard Companion firmware");
  Serial.println("Reference target: ESP32-S3-DevKitC-1 N8R8 + OV2640 DVP camera.");
  Serial.println("Camera wiring is provisional; see docs/camera-selection.md.");
  pinMode(kCaptureButtonPin, INPUT_PULLUP);

  const CameraStatus status = camera.begin();
  cameraReady = status == CameraStatus::Ready;
  Serial.printf("Camera: %s\n", statusText(status));
}

void loop() {
  if (!cameraReady) {
    delay(250);
    return;
  }

  if (digitalRead(kCaptureButtonPin) == LOW && !buttonLatched) {
    delay(30);
    if (digitalRead(kCaptureButtonPin) == LOW) {
      buttonLatched = true;
      captureOnButtonPress();
    }
  } else if (digitalRead(kCaptureButtonPin) == HIGH) {
    buttonLatched = false;
  }

  delay(5);
}

