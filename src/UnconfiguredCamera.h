#pragma once

#include "CameraAdapter.h"

class UnconfiguredCamera final : public CameraAdapter {
 public:
  CameraStatus begin() override { return CameraStatus::NotConfigured; }

  CameraStatus captureJpeg(CameraFrame& frame) override {
    frame = {};
    return CameraStatus::NotConfigured;
  }
};

