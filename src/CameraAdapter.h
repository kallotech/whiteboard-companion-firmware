#pragma once

#include <cstddef>
#include <cstdint>

enum class CameraStatus : uint8_t {
  Ready,
  NotConfigured,
  CaptureFailed,
};

struct CameraFrame {
  const uint8_t* data = nullptr;
  size_t size = 0;
};

// Hardware-specific camera support belongs behind this interface. The CAD
// currently contains no selected camera module or pin map, so the default
// implementation deliberately reports NotConfigured.
class CameraAdapter {
 public:
  virtual ~CameraAdapter() = default;
  virtual CameraStatus begin() = 0;
  virtual CameraStatus captureJpeg(CameraFrame& frame) = 0;
};

