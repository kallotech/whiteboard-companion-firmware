#include "Ov2640Camera.h"

#include <Arduino.h>
#include <esp_camera.h>

namespace {
// Reference wiring for an ESP32-S3-WROOM with a 24-pin DVP OV2640 module.
// Verify the module's connector pinout and the exact DevKitC-1 variant before
// building a carrier PCB or connecting hardware.
constexpr int kCameraPwdn = 38;
constexpr int kCameraReset = -1;
constexpr int kCameraXclk = 15;
constexpr int kCameraSda = 4;
constexpr int kCameraScl = 5;
constexpr int kCameraD0 = 11;
constexpr int kCameraD1 = 9;
constexpr int kCameraD2 = 8;
constexpr int kCameraD3 = 10;
constexpr int kCameraD4 = 12;
constexpr int kCameraD5 = 18;
constexpr int kCameraD6 = 17;
constexpr int kCameraD7 = 16;
constexpr int kCameraVsync = 6;
constexpr int kCameraHref = 7;
constexpr int kCameraPclk = 13;
}  // namespace

CameraStatus Ov2640Camera::begin() {
  if (!psramFound()) {
    Serial.println("Camera needs PSRAM; use the DevKitC-1 N8R8 variant.");
    return CameraStatus::InitializationFailed;
  }

  camera_config_t config{};
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = kCameraD0;
  config.pin_d1 = kCameraD1;
  config.pin_d2 = kCameraD2;
  config.pin_d3 = kCameraD3;
  config.pin_d4 = kCameraD4;
  config.pin_d5 = kCameraD5;
  config.pin_d6 = kCameraD6;
  config.pin_d7 = kCameraD7;
  config.pin_xclk = kCameraXclk;
  config.pin_pclk = kCameraPclk;
  config.pin_vsync = kCameraVsync;
  config.pin_href = kCameraHref;
  config.pin_sccb_sda = kCameraSda;
  config.pin_sccb_scl = kCameraScl;
  config.pin_pwdn = kCameraPwdn;
  config.pin_reset = kCameraReset;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

  const esp_err_t result = esp_camera_init(&config);
  if (result != ESP_OK) {
    Serial.printf("Camera initialization failed: 0x%X\n", result);
    return CameraStatus::InitializationFailed;
  }

  return CameraStatus::Ready;
}

CameraStatus Ov2640Camera::captureJpeg(CaptureSummary& summary) {
  summary = {};
  camera_fb_t* frame = esp_camera_fb_get();
  if (frame == nullptr) {
    return CameraStatus::CaptureFailed;
  }

  if (frame->format != PIXFORMAT_JPEG) {
    esp_camera_fb_return(frame);
    return CameraStatus::CaptureFailed;
  }

  summary.jpegBytes = frame->len;
  esp_camera_fb_return(frame);
  return CameraStatus::Ready;
}

