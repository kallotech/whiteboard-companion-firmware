#pragma once

#include "CameraAdapter.h"

class Ov2640Camera final : public CameraAdapter {
 public:
  CameraStatus begin() override;
  CameraStatus captureJpeg(CaptureSummary& summary) override;
};

