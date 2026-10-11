#pragma once

#include <cstddef>
#include <cstdint>

enum class CameraStatus : uint8_t {
  Ready,
  InitializationFailed,
  CaptureFailed,
};

struct CaptureSummary {
  size_t jpegBytes = 0;
};

// The camera driver stays behind this small interface so another supported
// sensor module can replace OV2640 without changing the button logic.
class CameraAdapter {
 public:
  virtual ~CameraAdapter() = default;
  virtual CameraStatus begin() = 0;
  virtual CameraStatus captureJpeg(CaptureSummary& summary) = 0;
};

